#include "integrators/flatIntegrator.h"

Color24 
FlatIntegrator::Li( const Ray& ray,
                    const Scene& scene,
                    Sampler& sampler )
{
    Color24 L(0,0,0); // The radiance
    // Find closest ray intersection or return background radiance.
    SurfaceInteraction isect;  
    if (!scene.intersect(ray, &isect)) {
        // This might be just:
        // L = scene.background->sample(ray);
    }
    else {
        // Some form of determining the incoming radiance at the ray's origin.
        // For this integrator, it might just be:
        // Polymorphism in action.
        // FlatMaterial *fm = dynamic_cast< FlatMaterial *>( isect.primitive->get_material() );
        // // Assign diffuse color to L.
        // L = fm->kd(); // Call a method present only in FlatMaterial.
    }
    return L;
} 