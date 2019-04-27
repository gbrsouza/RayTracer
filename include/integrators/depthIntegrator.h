#ifndef _DEPTH_INTEGRATOR_H_
#define _DEPTH_INTEGRATOR_H_

#include "samplerIntegrator.h"

/**
 * @brief The color associated with a hit is calculated
 * as follow: normalize the depth hit in [Zmin,Zmax] and 
 * use this normalized value to linearly interpolate a 
 * color between white and black. This approach produces
 * a gray scale image representing the depth map of the 
 * scene.
 */
class DepthIntegrator : public SamplerIntegrator {

};

#endif