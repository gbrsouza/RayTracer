#ifndef _AMBIENT_LIGHT_
#define _AMBIENT_LIGHT_

/**
 * @file ambientLight.h
 * @author Gabriel Araújo de Souza (gabriel_feg@hotmail.com)
 * @brief  A new loght type
 * @version 0.1
 * @date 2019-05-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "light.h"

/**
 * @brief a class to represent a ambient light 
 */
class AmbientLight : public Light {
 
public:

    /**
     * @brief Construct a new Ambient Light object
     * @param intensity the intensity of light
     */
    AmbientLight ( point3 intensity )
        : Light{intensity} {}

    AmbientLight ()
        : Light{ Vec3(0.1, 0.1, 0.1) }{}

    /**
     * @brief Destroy the Ambient Light object
     */
    ~AmbientLight(){ /*empty*/ }

    Vec3 Li(
        const SurfaceInteraction &isect,
        vector *wi,
        VisibilityTester *vt) const;

    bool is_ambient(){ return true;} 

};


#endif