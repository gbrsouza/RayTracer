#include "lights/directionalLight.h"
Vec3 DirectionalLight::Li(
        const SurfaceInteraction &isect,
        vector *wi,
        VisibilityTester *vt) const
{
    *wi = unit_vector(direction);

    //std::cout << this->bounding_box_world.pMin << " , " << this->bounding_box_world.pMax << std::endl;
    //std::cout << this->bounding_box_world.diagonal() << std::endl;
    point3 position = isect.p + (*wi) * bounding_box_world.diagonal();//unit_vector(isect.p + direction) * bounding_box_world.diagonal();
    *vt = VisibilityTester(isect, SurfaceInteraction {position});

    return intensity;
}