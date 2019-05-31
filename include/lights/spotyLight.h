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

private:

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

    /**
     * @brief Destroy the Spoty Light object
     */
    ~SpotyLight (){ /*empty*/ }

    /**
     * @brief Get the position object
     * 
     * @return point3 the positon of light
     */
    point3 get_position () { return position; }

    /**
     * @brief Get the point at object
     * 
     * @return point3  the point at
     */
    point3 get_point_at () { return point_at; }

    /**
     * @brief Get the cutoff object
     * 
     * @return int  the cutoff
     */
    int get_cutoff () { return cutoff; }

    /**
     * @brief Get the falloff object
     * 
     * @return int the falloff
     */
    int get_falloff () { return falloff; }

    Vec3 Li(
        const SurfaceInteraction &isect,
        vector *wi,
        VisibilityTester *vt) const;

};

#endif