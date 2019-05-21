#include "lights/pointLight.h"

Vec3 PointLight::Li(
    const SurfaceInteraction &isect,
    vector *wi,
    VisibilityTester *vt) const
{
    SurfaceInteraction lIsect;
    lIsect.p = this->position;

    vt = new VisibilityTester(isect, lIsect);
    // wi = vt->shoot_ray();

    return intensity;
}
