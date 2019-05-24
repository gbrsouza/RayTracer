#include "lights/spotyLight.h"
#include "../vec3.cpp"

Vec3 SpotyLight::Li(
        const SurfaceInteraction &isect,
        vector *wi,
        VisibilityTester *vt) const
{
    *wi = unit_vector(this->position - isect.p);
    *vt = VisibilityTester(isect, SurfaceInteraction {this->position});

    auto w = -*wi;

    auto cos_cutoff = cos(cutoff * RADIANS);
    auto cos_falloff = cos(falloff * RADIANS);

    vector light_vector = point_at - position;
    float theta = dot(light_vector, w) / (norm(light_vector) * norm(w));

    if ((theta) < cos_cutoff ) return Vec3(0,0,0);
    if ((theta) > cos_falloff) return intensity;

    float delta = (theta - cos_cutoff) / (cos_falloff - cos_cutoff);
    return pow(delta, 4) * intensity;
}