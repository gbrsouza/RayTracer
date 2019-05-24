#include "lights/directionalLight.h"
#include "../vec3.cpp"

Vec3 DirectionalLight::Li(
        const SurfaceInteraction &isect,
        vector *wi,
        VisibilityTester *vt) const
{
    *wi = unit_vector(-direction);
    return intensity;
}