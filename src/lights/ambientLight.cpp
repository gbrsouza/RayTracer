#include "lights/ambientLight.h"

Vec3 AmbientLight::Li(
    const SurfaceInteraction &isect,
    vector *wi,
    VisibilityTester *vt) const
{
    // TODO
    // vt = new VisibilityTester(isect, )
    UNUSED(isect);
    UNUSED(wi);
    UNUSED(vt);
    return intensity;
}
    