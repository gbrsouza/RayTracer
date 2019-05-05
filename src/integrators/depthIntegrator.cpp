#include "integrators/depthIntegrator.h"
#include "../vec3.cpp"

void 
DepthIntegrator::preprocess( const Scene& scene )
{

}

// @Override
Color24 
DepthIntegrator::Li( const Ray& ray,
                     const Scene& scene,
                     Sampler& sampler ) 
                     const
{

    SurfaceInteraction isect;  
    scene.intersect(ray, &isect);

     // interpolation
    float t = isect.Zmax - isect.Zmin;
    Color24 c = near_color + (far_color - near_color) * t;

    return c;
}
