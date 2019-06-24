#include "lights/pointLight.h"

Vec3 PointLight::Li(
    const SurfaceInteraction &isect,
    vector *wi,
    VisibilityTester *vt) const
{
    *wi = unit_vector(this->position - isect.p);

    *vt = VisibilityTester(isect, SurfaceInteraction {this->position});

    return this->intensity;
}
