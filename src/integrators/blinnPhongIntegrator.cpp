#include "integrators/blinnPhongIntegrator.h"

Color24 
BlinnPhongIntegrator::Li( const Ray& ray,
    const Scene& scene,
    Sampler& sampler ) const
{
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
        
        // TODO formula
    }

    return L;
}
