#ifndef _BLINNPHONG_INTEGRATOR_
#define _BLINNPHONG_INTEGRATOR_

#include "samplerIntegrator.h"

class BlinnPhongIntegrator : public SamplerIntegrator {

public:

// @Override
void 
preprocess( const Scene& scene )
{ /*empty*/ }

// @Override
Color24 
Li( const Ray& ray,
    const Scene& scene,
    Sampler& sampler ) const;

};

#endif