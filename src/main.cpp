#include <iostream>
#include <string>
#include <fstream>

#include "background.h"
#include "canvas.h"
#include "common.h"

int main (){
    
    Buffer color_buffer (200, 100);

    Color bl = Color(0, 0, 51); //<!-- bottom left -->
    Color tl = Color(0, 255, 51); //<!-- top left -->
    Color tr = Color(255, 255, 51); //<!-- top right -->
    Color br = Color(255, 0, 51); //<!-- bottom right -->

    Background bg = Background(bl, tl, tr, br);
    auto w = color_buffer.get_width();
    auto h = color_buffer.get_heigth();


    for (int j = h-1; j >= 0; j--){
        for (int i = 0; i < w; i++){
            auto color = bg.sample(float(i)/float(2), float(j)/float(h));
            color_buffer.color_pixel(i, j, color);
        }
    }


    return 0;
}