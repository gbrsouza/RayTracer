#include "cameras/orthographic_camera.h"
#include "vec3.cpp"
#include <iostream>

Ray OrthographicCamera::generate_ray(int x, int y)
{
    // mapping pixels to screen space
    float u = l + ((r - l) * (x + 0.5)) / get_width();
    float v = b + ((t - b) * (y + 0.5)) / get_height();

    // determining the Camera frame
    vector gaze = this->target - this->position;
    
    vector wVec = unit_vector(-gaze);    
    vector uVec = unit_vector(cross(vUp, wVec));
    vector vVec = unit_vector(cross(wVec, uVec));
    
    // Generating the ray
    point3 o = position + ( u * uVec) + (v * vVec); //<! ray's origin
    point3 d = -wVec; //<! ray's direction
    
    return Ray(o, d);
}