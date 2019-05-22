#include "lights/pointLight.h"
#include "../vec3.cpp"

Vec3 PointLight::Li(
    const SurfaceInteraction &isect,
    vector *wi,
    VisibilityTester *vt) const
{
    *wi = unit_vector(this->position - isect.p);

    SurfaceInteraction lIsect;
    lIsect.p = this->position;

    vt = new VisibilityTester(isect, lIsect);
    // wi = vt->shoot_ray();

    return intensity;
}
