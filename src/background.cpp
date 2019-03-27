#include "background.h"
#include "vec3.cpp"

#include<iostream>
Color Background::sample ( float i, float j ){
    
    Color q11 = colors[0];
    Color q12 = colors[1];
    Color q21 = colors[3];
    Color q22 = colors[2];

    Color r1 = q12 + i*(q22 - q12);
    Color r2 = q11 + i*(q21 - q11);
    std::cout << i << " " << j << "\n";

    return r1 + (r2 - r1)*j;

}
