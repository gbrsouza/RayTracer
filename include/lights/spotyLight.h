#ifndef _SPOTY_LIGHT_H
#define _SPOTY_LIGHT_H

/**
 * @file spotyLight.h
 * @author Gabriel Araújo de Souza (gabriel_feg@hotmail.com)
 * @brief  The new light type
 * @version 0.1
 * @date 2019-05-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "light.h"


/**
 * @brief a class to represent a spoty light
 * 
 */
class SpotyLight : public Light {

point3 position;
point3 point_at;
int cutoff;
int falloff;

public:

    /**
     * @brief Construct a new Spoty Light object
     * 
     * @param intensity  The intensity of light
     * @param position 
     * @param point_at 
     * @param cutoff 
     * @param falloff 
     */
    SpotyLight ( 
        point3 intensity,
        point3 position,
        point3 point_at,
        int cutoff,
        int falloff
    ) : Light{intensity},
        position{position},
        point_at{point_at},
        cutoff{cutoff},
        falloff{falloff} {}

    ~SpotyLight (){ /*empty*/ }


};

#endif