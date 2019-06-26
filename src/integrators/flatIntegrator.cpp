#include "integrators/flatIntegrator.h"

Color24 
FlatIntegrator::Li( const Ray& ray,
                    const Scene& scene,
                    Sampler& sampler )
                    const
{
    UNUSED(sampler);
    Color24 L(0,0,0); // The radiance
    auto img_dim = camera->get_film()->get_dimension();
    // Find closest ray intersection or return background radiance.
    SurfaceInteraction isect;  
    if (!scene.intersect(ray, &isect)) {
        
        // This might be just:
        float _x = float(ray.x)/float(img_dim.x());
        float _y = float(ray.y)/float(img_dim.y());
        L = scene.background->sample(_x, _y);
    
    }
    else {
    
        // Some form of determining the incoming radiance at the ray's origin.
        // For this integrator, it might just be:
        // Polymorphism in action.
        FlatMaterial *fm = dynamic_cast< FlatMaterial *>( isect.m );
       
        // Assign diffuse color to L.
        L = fm->get_color(); // Call a method present only in FlatMaterial.
    
    }

    return L;

} 