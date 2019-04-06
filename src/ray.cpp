#include "ray.h"
#include "vec3.cpp"

Vec3 Ray::operator() (float t)
{ return o + (t*d); }