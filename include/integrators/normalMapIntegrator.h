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

};

#endif