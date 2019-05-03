#ifndef _INTEGRATOR_H_
#define _INTEGRATOR_H_

#include "../scene.h"

/**
 * @brief abstract class for represents an entity 
 * that has a camera,  and receives a scene to
 * generate an image from.
 */
class Integrator {

public:

    /**
     * @brief Destroy the Integrator object
     */
    ~Integrator() { /*empty*/ }
   
    /**
     * @brief renderize a scene
     * @param scene the scene for renderize 
     */
    virtual void render( const Scene& scene) = 0;

};

#endif