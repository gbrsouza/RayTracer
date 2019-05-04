#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <cstring>
#include <memory>

#include "common.h"
#include "raster.h"
#include "scene.h"
#include "integrators/flatIntegrator.h"
#include "integrators/samplerIntegrator.h"
#include "xml-parser.h"
#include "cameras/orthographic_camera.h"
#include "cameras/pespective_camera.h"
#include "primitives/aggregatePrimitive.h"
#include "surfaceInteraction.h"

// === The 3 global objects.
std::unique_ptr<Camera> g_camera;         // The single camera object.
std::unique_ptr<Scene> g_scene;           // The scene.
std::unique_ptr<Integrator> g_integrator; // The integrator.

void init_engine( const char* filename );
void run();

int main (int argc, char *argv[])
{

	std::string name;
	if (argc == 2)
		name = argv[1];
	else {
		std::cout << "Please, specify the xml file with the scene specification.\n";
		std::cout << "./exe.out <xml_file>\n";
		return 0;	
	}
  
    std::cout << "+=========================================+\n"
              << "|           Ray Tracer -- v0.3            |\n"
              << "|     copyright Souza, Gabriel A. 2019.   |\n"
              << "|           powered by TinyXML-2          |\n" 
              << "+=========================================+\n";
    
    init_engine( name.c_str() );

    auto d = g_camera->get_film()->get_dimension();
    std::cout << "[2] Starting ray tracing progress.\n";
    std::cout << "    Image dimensions in pixels (W x H): " << d.x() << " x " << d.y() << std::endl;
    std::cout << "    Ray tracing is usually a slow process, please be patient:\n"; 
    
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    run();

    std::cout << "\n>>>Done!\n\n";
    end = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>
                          (end-start).count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds << "ms\n";

    // Send image color buffer to the output file.
    g_camera->get_film()->write_img( );
    std::cout << "\n[3] Image successfuly written to file " << 
                 g_camera->get_film()->get_filename() << ".ppm\n";

	return 0;
	
}

void init_engine( const char* filename )
{
    std::cout << "\n[1] Scene file parsing initiated...\n";

    ParserXML parser = ParserXML(filename);
  
    try { parser.run();  }
    catch(std::string e)
    {   std::cout << e << '\n'; 
        std::cerr << e << '\n'; }

    // create a integrator
    g_camera = std::make_unique<Camera>( parser.camera );
    std::shared_ptr<Sampler> sampler(new Sampler());
    g_integrator = std::make_unique<FlatIntegrator>(parser.camera, sampler);

    // create a aggregate primitive
    AggregatePrimitive *aggregate = new AggregatePrimitive(parser.primitives);
    std::shared_ptr<Primitive> agg(aggregate);

    // create a empty vector of lights 
    std::shared_ptr<Light>l(new Light()); 
    std::vector<std::shared_ptr<Light>> lights = {l};

    //create a background
    std::shared_ptr<Background> bg(parser.background);

    Scene scene = Scene(agg, bg, lights);

    g_scene = std::make_unique<Scene> (scene);
    
    std::cout << "\n>>> Parsing scene successfuly done! <<<  \n"; 
    
}

void run()
{
    g_integrator->render( *g_scene ); // Activate the main loop
}

// [3] Enter the ray tracing main loop; this is the default render() method.
// Notice that the FlatIntegrator does not need to override this method.
// It relies on the version provided by the base class (SampleIntegrator).
void SamplerIntegrator::render( const Scene& scene ) {
    
    // Always call the preprocess() before doing any rendering.
    // This might be just an empty method, or not, depending on the integrator's needs.
    // preprocess(scene);

    // This might just be a tile (part) of an image, rendered in parallel.
    Point2i img_dim = g_camera->get_film()->get_dimension();
    
    for ( int y = 0 ; y < img_dim.y() ; y++ ) {
        for( int x = 0 ; x < img_dim.x() ; x++ ) {
            
            Ray ray = g_camera->generate_ray( x, y ); // Generate the ray from (x,y)
        
            //Assume the original pixel color is the background
            Color24 L = ( scene.intersect_p(ray) ) ? 
                        Li( ray, scene, *sampler ) :
                        scene.background->sample( float(x)/float(img_dim.x()),
                                                  float(y)/float(img_dim.y()) );

            // auto color = parser.background->sample(float(j)/float(w), float(i)/float(h));
           
            // for ( auto p : scene ) { // Traverse each object.
            //     SurfaceInteraction surface;
            //     bool hit = p->intersect(r, &surface);
            //     if (hit) color = Color (255,0,0); 
            // }

            g_camera->get_film()->add_sampler( Point2i( x, y, 0 ), L ); // Set color of pixel (x,y) to L.
        }
    }

}