#include "background.h"
#include "vec3.cpp"

Color Background::sample ( float i, float j){
    
    auto q11 = colors[0];
    auto q12 = colors[1];
    auto q21 = colors[3];
    auto q22 = colors[2];

    auto x1 = q12.x();
    auto x2 = q21.x();
    auto y1 = q11.y();
    auto y2 = q22.y();

    auto r1 = ((x2-x1-i)/(x2-x1))*q11 + (i/(x2-x1))*q21;
    auto r2 = ((x2-x1-i)/(x2-x1))*q12 + (i/(x2-x1))*q22;

    return  ((y2-y1-j)/(y2-y1))*r1 + (j/(y2-y1))*r2; 
}
