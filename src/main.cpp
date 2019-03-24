#include <iostream>
#include <string>
#include <fstream>

#include "background.h"
#include "common.h"

int main (){

    Ray ray = Ray(1,1,1);
    Background bg = Background(Color(5,5,10), 
                               Color(5,255,10),
                               Color(255,5,10),
                               Color(255,255,10));

    std::ofstream myfile;
    std::string filename = "out";
 	
 	myfile.open (filename + OUTPUT_EXTENSION);
  	myfile << OUTPUT_INDEX << "\n";
  	myfile << 200 << " " 
  		   << 100 << "\n";
  	myfile << MAX_COLOR_VALUE << "\n";

    Color c = Vec3(1,1,1);

    for (int i=0; i < 100; i++){
        for (int j=0; j <200; j++){
            ray = Ray(i, j, 10);
            c = bg.get_color(ray);
            
            myfile << int(abs(c.r())) << " " << int(abs(c.g())) << " " << int(abs(c.b())) << " ";
        }
        myfile << "\n";
    }

	myfile.close();

    return 0;
}