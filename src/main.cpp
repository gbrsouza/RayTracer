#include <iostream>
#include <string>
#include <fstream>

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
 
    ParserXML parser = ParserXML(name);
  
    try { parser.run();  }
    catch(std::string e)
    { std::cerr << e << '\n'; }
    
    int w = parser.buffer->get_width();
    int h = parser.buffer->get_heigth();

    Camera *cam = parser.camera;
    auto scene  = parser.scene;

    std::cout << "size:" << scene.size() << std::endl;

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

    Raster raster = Raster(parser.buffer, parser.output);
    raster.draw();
    
	return 0;
	
}
