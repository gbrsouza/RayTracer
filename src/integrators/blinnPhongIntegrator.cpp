#include "integrators/blinnPhongIntegrator.h"
#include "../vec3.cpp"

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
        
        point3 KaIa = Vec3(0.0, 0.0, 0.0);
        vector wi;
        VisibilityTester *vt;

        BlinnMaterial *fm = dynamic_cast< BlinnMaterial *>( isect.m );
        for ( auto l : scene.lights ){
            std::string type = typeid(l.get()).name(); 
            if ( type.compare("AmbientLight") == 0 )  
                KaIa = fm->get_ka() * l->Li(isect, &wi, vt);
            else {

                auto Ii = l->Li(isect, &wi, vt);
                auto n = unit_vector(isect.n);
                auto wo = unit_vector(isect.wo);

                auto h = wo + wi;
                h.make_unit_vector();
                        
                L += fm->get_kd() * Ii * fmax(0.0, dot(n, wo));
                L += fm->get_ks() * Ii * pow(fmax(0.0, dot(n, h)), fm->get_ge());
            }
        }

        L += KaIa;
    }
    
    return L * 255;
}
