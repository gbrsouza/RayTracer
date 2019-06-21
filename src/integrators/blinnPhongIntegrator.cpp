#include "integrators/blinnPhongIntegrator.h"
#include "../vec3.cpp"
#include "lights/directionalLight.h"

Color24 
BlinnPhongIntegrator::Li( const Ray& ray,
    const Scene& scene,
    Sampler& sampler ) const
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
        return scene.background->sample(_x, _y);
    
    }
    else {

        point3 KaIa = Vec3(0.0, 0.0, 0.0);
        vector wi;
        VisibilityTester vt;

        BlinnMaterial *fm = dynamic_cast< BlinnMaterial *>( isect.m );
        auto ka = fm->get_ka();
        auto kd = fm->get_kd();
        auto ks = fm->get_ks();
        auto gloss = fm->get_ge();

        for ( auto l : scene.lights ){

            l->set_bounding_box( this->bounding_box_world );
        
            if ( l->is_ambient() ) {
                KaIa = ka * l->get_intensity();
            }else {

                auto Ii = l->Li(isect, &wi, &vt);
                auto n = isect.n;

                auto wo = isect.wo;
                auto h = wo + wi;
                h.make_unit_vector();

                if (vt.unoccluded(scene)){
                    L += kd * Ii * fmax(0.0, dot(n, wi));
                    L += ks * Ii * pow(fmax(0.0, dot(n, h)), gloss);
                }

                // L += kd * Ii * fmax(0.0, dot(n, wi));
                // L += ks * Ii * pow(fmax(0.0, dot(n, h)), gloss);
                
            }
        }

        L += KaIa;
       // std::cout << "L: " << L << std::endl;
        L *= 255;
        return {fmin(255.0, L.r()), fmin(255.0, L.g()), fmin(255.0, L.b())};
    }
}
