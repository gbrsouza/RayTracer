#include "integrators/depthIntegrator.h"
#include "../vec3.cpp"

void 
DepthIntegrator::preprocess( const Scene& scene )
{
    auto img_dim = camera->get_film()->get_dimension();
    SurfaceInteraction isect;  
    for ( int y = 0 ; y < img_dim.y() ; y++ ) {
        for( int x = 0 ; x < img_dim.x() ; x++ ) {
            
            Ray ray = camera->generate_ray( x, y ); // Generate the ray from (x,y)
            if (scene.intersect(ray, &isect)){
                if (isect.t < zMin) zMin = isect.t;
                if (isect.t > zMax) zMax = isect.t;
            }
        }
    }
}

// @Override
Color24 
DepthIntegrator::Li( const Ray& ray,
                     const Scene& scene,
                     Sampler& sampler ) 
                     const
{

    Color24 L(0,0,0); // The radiance
    
    // Find closest ray intersection or return background radiance.
    SurfaceInteraction isect;  
    if (!scene.intersect(ray, &isect)) {
        
        // This might be just:
        L = this->far_color;
    
    }
    else {
        //interpolation 
        float delta = (isect.t - zMin) / (zMax - zMin); 
        auto r = near_color.r() + (far_color.r() - near_color.r()) * delta;
        auto g = near_color.g() + (far_color.g() - near_color.g()) * delta;
        auto b = near_color.b() + (far_color.b() - near_color.b()) * delta;
        
        L = Color24(r, g, b);
    
    }

    return L;

}
