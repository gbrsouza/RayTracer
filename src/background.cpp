#include "background.h"
#include "vec3.cpp"

Color Background::get_color (Ray &ray){
    // define Xs and Ys
    const Vec3 q11 = this->colors[0]; 
    const Vec3 q12 = this->colors[1]; 
    const Vec3 q21 = this->colors[2]; 
    const Vec3 q22 = this->colors[3]; 
    
    float x1 = q11.x();
    float x2 = q22.x();
    float y1 = q11.y();
    float y2 = q22.y();
    
    // calculate Rs
    Ray r1 = ((x2-ray.x())/(x2-x1))*q11 + ((ray.x()-x1)/(x2-x1))*q21;
    Ray r2 = ((x2-ray.x())/(x2-x1))*q12 + ((ray.x()-x1)/(x2-x1))*q22;

    return ((y2-ray.y())/(y2-y1))*r1 + ((ray.y()-y1)/(y2-y1))*r2;
}
