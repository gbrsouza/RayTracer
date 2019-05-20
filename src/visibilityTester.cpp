#include "visibilityTester.h"
#include "vec3.cpp"

bool VisibilityTester::unoccluded(
    const Scene &scene)
{
    Ray r = shoot_ray();
    // TODO
}

Ray VisibilityTester::shoot_ray() const 
{
    vector origin = p0.p;
    vector destiny = p1.p;
    vector v = destiny - origin;
    return Ray(origin, v);
}