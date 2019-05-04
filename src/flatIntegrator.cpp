#include "integrators/flatIntegrator.h"

Color24 
FlatIntegrator::Li( const Ray& ray,
                    const Scene& scene,
                    Sampler& sampler )
                    const
{
    Color24 L(0,0,0); // The radiance
    // Find closest ray intersection or return background radiance.
    SurfaceInteraction isect;  
    scene.intersect(ray, &isect);
    
    // Some form of determining the incoming radiance at the ray's origin.
    // For this integrator, it might just be:
    // Polymorphism in action.
    FlatMaterial *fm = dynamic_cast< FlatMaterial *>( isect.m );
    
    // assign diffuse color to L.
     L = fm->get_color(); // Call a method present only in FlatMaterial.
    
    return L;
} 