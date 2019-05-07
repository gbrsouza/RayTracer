#ifndef _NORMAL_MAP_INTEGRATOR_
#define _NORMAL_MAP_INTEGRATOR_

#include "samplerIntegrator.h"

/**
 * @brief The color of a hit is determined by making the
 * normal at the hit point have length 1, and treating its
 * coordinate values as RGB color, where the value in [0,1]
 * -> [0,255]. This is called the normal map of an image. 
 */
class NormalMapIntegrator : public SamplerIntegrator {

public:

	/**
	 * @brief Construct a new Normal Map Integrator object
	 * 
	 * @param cam 
	 * @param sampler 
	 */
	NormalMapIntegrator( std::shared_ptr<Camera> cam,
					std::shared_ptr<Sampler> sampler)
			: SamplerIntegrator{cam, sampler} {}

	// @Override
    void 
    preprocess( const Scene& scene );

    // @Override
    Color24 
    Li( const Ray& ray,
        const Scene& scene,
        Sampler& sampler ) const;

};

#endif