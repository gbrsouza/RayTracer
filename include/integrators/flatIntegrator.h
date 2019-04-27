#ifndef _FLAT_INTEGRATOR_H_
#define _FLAT_INTEGRATOR_H_

#include "samplerIntegrator.h"

/**
 * @brief Each time a ray hits an object, regardless 
 * of the objects normal or the presence (or absence) 
 * of lights, the color is always the same for the 
 * entire object.
 */
class FlatIntegrator : public SamplerIntegrator{

};


#endif