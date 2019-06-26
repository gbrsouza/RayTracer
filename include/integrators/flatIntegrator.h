#ifndef _FLAT_INTEGRATOR_H_
#define _FLAT_INTEGRATOR_H_

/**
 * @file flatIntegrator.h
 * @author Gabriel Araújo de Souza (gabriel_feg@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "samplerIntegrator.h"

/**
 * @brief Each time a ray hits an object, regardless 
 * of the objects normal or the presence (or absence) 
 * of lights, the color is always the same for the 
 * entire object.
 */
class FlatIntegrator : public SamplerIntegrator{

public:

    /**
     * @brief Construct a new Flat Integrator object
     * 
     * @param cam      The camera
     * @param sampler  The sampler
     */
    FlatIntegrator( std::shared_ptr<Camera> cam,
                    std::shared_ptr<Sampler> sampler)
        : SamplerIntegrator{cam, sampler} {}

    FlatIntegrator( Camera *& cam, 
                    std::shared_ptr<Sampler> &sampler)
        : SamplerIntegrator{cam, sampler}{}

    /**
     * @brief Destroy the Flat Integrator object
     */
    ~FlatIntegrator(){/*empty*/}

    // @Override
    void 
    preprocess( const Scene& scene )
    { UNUSED(scene); }

    // @Override
    Color24 
    Li( const Ray& ray,
        const Scene& scene,
        Sampler& sampler ) const;

};


#endif