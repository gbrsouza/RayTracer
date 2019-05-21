#ifndef _LIGHT_H_
#define _LIGHT_H_

/**
 * @file light.h
 * @author Gabriel Araújo de Souza (gabriel_feg@hotmail.com)
 * @brief  The abstract class to represent lights
 * @version 0.1
 * @date 2019-05-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "common.h"
#include "surfaceInteraction.h"
#include "visibilityTester.h"

class VisibilityTester;
class SurfaceInteraction;

class Light { 

protected:

    point3 intensity; //<! The intensity of light 

public:

    /**
     * @brief Construct a new Light object
     * @param intensity the instensity
     */
    Light( point3 intensity ) :
        intensity{intensity} {}
    
    /**
     * @brief Construct a new Light object
     */
    Light() : intensity{ Vec3(0.1, 0.1, 0.1)}{}
    
    /**
     * @brief Destroy the Light object
     */
    ~Light(){ /*empty*/ }

    /**
     * @brief The light's contribution to a point
     * 
     * @param isect   The pixel
     * @param wi      The vector of pixel to light
     * @param vt      The visitor tester
     * @return Vec3   The light's contribution
     */
    virtual Vec3 Li(
        const SurfaceInteraction &isect,
        vector *wi,
        VisibilityTester *vt) const = 0;     

};

#endif