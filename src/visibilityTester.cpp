#include "visibilityTester.h"
#include "vec3.cpp"

bool VisibilityTester::unoccluded(
    const Scene &scene)
{
    return !scene.intersect(*shoot_ray().get(), &this->p1);
}

std::shared_ptr<Ray> VisibilityTester::shoot_ray() const 
{
    vector origin = p0.p;
    vector destiny = p1.p;
    vector v = destiny - origin;

    std::shared_ptr<Ray> r (new Ray(origin, v));
    r->tMax = 1;
    return  r;
}