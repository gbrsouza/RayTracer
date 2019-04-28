#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>

#include "common.h"
#include "raster.h"
#include "xml-parser.h"
#include "cameras/orthographic_camera.h"
#include "cameras/pespective_camera.h"
#include "primitives/primitive.h"
#include "surfaceInteraction.h"

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
    
    std::cout << "\n[1] Scene file parsing initiated...\n";

    ParserXML parser = ParserXML(name);
  
    try { parser.run();  }
    catch(std::string e)
    {   std::cout << e << '\n'; 
        std::cerr << e << '\n'; }
    
    std::cout << "\n>>> Parsing scene successfuly done! <<<  \n"; 
    
    int w = parser.buffer->get_width();
    int h = parser.buffer->get_heigth();

    Camera *cam = parser.camera;
    auto scene  = parser.scene;

    std::cout << "[2] Starting ray tracing progress.\n";
    std::cout << "    Image dimensions in pixels (W x H): " << w << " x " << h << std::endl;
    std::cout << "    Ray tracing is usually a slow process, please be patient:\n"; 
    
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    for (int i = h-1; i >= 0; i--){
        for (int j = 0; j < w; j++){
            Ray r = cam->generate_ray(j,i);

            // std::cout << "pixel (" << i << ", " << j << ") ";
            // std::cout << r << std::endl;
            
            auto color = parser.background->sample(float(j)/float(w), float(i)/float(h));
           
            for ( auto p : scene ) { // Traverse each object.
                SurfaceInteraction surface;
                bool hit = p->intersect(r, &surface);
                if (hit) color = Color (255,0,0); 
            }
           
            parser.buffer->color_pixel(j, i, color);
        }
    }

    std::cout << "\n>>>Done!\n\n";
    end = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>
                          (end-start).count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds << "ms\n";

    Raster raster = Raster(parser.buffer, parser.output);
    raster.draw();
    
    std::cout << "\n[3] Image successfuly written to file " << parser.output << ".ppm\n";

	return 0;
	
}
