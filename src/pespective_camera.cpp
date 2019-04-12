#include "pespective_camera.h"
#include "vec3.cpp"

 Ray PespectiveCamera::generate_ray(int x, int y)
 {
    // Find the half-height and half-width
    auto hh = tan( (fovy*RADIANS) /2.0)*fdistance;
    auto hw = aspect * hh;
    
    float l,r,t,b;
    l = -hw; r= hw;
    b = -hh; t = hh;    

    // mapping pixels to screen space
    float u = l + ((r-l)*(x+0.5))/get_width();
    float v = b + ((t-b)*(y+0.5))/get_height();

    // determining the Camera frame
    vector gaze = this->target - this->position;
    
    vector w = -gaze;
    w.make_unit_vector();
    
    vector uVec = vUp.cross(vUp, w);
    // std::cout << "vUp:" << vUp;
    // std::cout << " w:" << w;
    // std::cout << "uVec" << uVec;
    uVec.make_unit_vector();

    vector vVec = w.cross(w, uVec);
    vVec.make_unit_vector();

    point3 e = this->position;

    // Generating the ray
    point3 o = e; //<! ray's origin
    point3 d = -(fdistance)*w + u*uVec + v*vVec; //<! ray's direction
    Ray ray = Ray(o, d);
    return ray;

 }