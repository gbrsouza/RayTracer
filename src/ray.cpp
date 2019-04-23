#include "ray.h"
#include "vec3.cpp"

Vec3 Ray::operator() (float t) const 
{ return o + (t*d); }