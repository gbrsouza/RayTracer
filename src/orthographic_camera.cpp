#include "orthographic_camera.h"
#include "vec3.cpp"
#include <iostream>
Ray OrthographicCamera::generate_ray(int x, int y)
{
    // mapping pixels to screen space
    float u = l + ((r-l)*(x+0.5))/get_width();
    float v = b + ((t-b)*(y+0.5))/get_height();

    // determining the Camera frame
    vector gaze = this->target - this->position;
    
    vector w = -gaze;
    w.make_unit_vector();
    
    vector uVec = cross(vUp, w);
    // std::cout << "vUp:" << vUp;
    // std::cout << " w:" << w;
    // std::cout << "uVec" << uVec;
    uVec.make_unit_vector();

    vector vVec = cross(w, uVec);
    vVec.make_unit_vector();

    point3 e = this->position;
    
    // Generating the ray
    point3 o = e + u*uVec + v*vVec; //<! ray's origin
    point3 d = -w; //<! ray's direction
    Ray ray = Ray(o, d);
    return ray;
}