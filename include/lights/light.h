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
    Light() : intensity{ 0.1, 0.1, 0.1 }{}
    
    /**
     * @brief Destroy the Light object
     */
    ~Light(){ /*empty*/ }

   // virtual float Li ();

};

#endif