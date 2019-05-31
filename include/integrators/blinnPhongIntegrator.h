#ifndef _BLINNPHONG_INTEGRATOR_
#define _BLINNPHONG_INTEGRATOR_

#include "samplerIntegrator.h"
#include "materials/blinnMaterial.h"

#include <typeinfo> //typeid
#include <math.h> //fmax

class BlinnPhongIntegrator : public SamplerIntegrator {

public:

    Bounds3 bounding_box_world;

    /**
     * @brief Construct a new Blinn Phong Integrator object
     * 
     */
    BlinnPhongIntegrator(
        std::shared_ptr<Camera> cam,
        std::shared_ptr<Sampler> sampler)
        : SamplerIntegrator{cam, sampler}{}

    ~BlinnPhongIntegrator(){ /*empty*/ }

    // @Override
    void 
    preprocess( const Scene& scene )
    { bounding_box_world = scene.world_bound; }

    // @Override
    Color24 
    Li( const Ray& ray,
        const Scene& scene,
        Sampler& sampler ) const;

    };

#endif