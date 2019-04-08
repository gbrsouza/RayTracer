#include <iostream>
#include <string>
#include <fstream>

#include "common.h"
#include "raster.h"
#include "xml-parser.h"
#include "orthographic_camera.h"

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
    
    int w = 40;
    int h = 30;
    point3 pos = point3(0,0,0);
    point3 target = point3(0,0,-10);
    Vec3 vUp = Vec3(0,1,1);
    Camera *cam = new OrthographicCamera(w,h,pos, target, vUp, -3.0, 3.0, -2.25, 2.25);

    for (int j = h-1; j >= 0; j--){
        for (int i = 0; i < w; i++){
            Ray r = cam->generate_ray(i,j);
            std::cout << "pixel (" << i << ", " << j << ") ";
            std::cout << r << std::endl;

            auto color = parser.background->sample(float(i)/float(w), float(j)/float(h));
            parser.buffer->color_pixel(i, j, color);
        }
    }

    Raster raster = Raster(parser.buffer, parser.output);
    raster.draw();
    
	return 0;
	
}
