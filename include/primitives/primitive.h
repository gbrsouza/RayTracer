#ifndef _PRIMITIVE_H_
#define _PRIMITIVE_H_

#include "../common.h"
#include "../ray.h"
#include "../materials/material.h"

class SurfaceInteraction;

/**
 * @brief This is an abstract class that helps us separate the 
 * geometric information from the appearance information (material).
 * A primitive might be a shape, but also it might be an acceleration
 * structure that holds other primitives. This class requires the 
 * intersection() method to be implemented.
 */
class Primitive {


public:

    Primitive () {}
    /**
     * @brief Destroy the Primitive object
     */
    virtual ~Primitive(){};
   
    /**
     * @brief   check if a ray intersect a primitive
     * 
     * @param r        the ray
     * @param surface  the surface of primitive
     * @return true    if the ray intersect the sphere
     * @return false   if the ray not intersect the sphere
     */
    virtual bool intersect ( const Ray& r,
                             SurfaceInteraction * surface)
                             const = 0;
   
    /**
     * @brief  check if a ray intersect a primitive
     * 
     * @param r        the ray 
     * @return true    if the ray intersect the sphere 
     * @return false   if the ray not intersect the sphere
     */
    virtual bool intersect_p( const Ray& r ) const = 0;

};

#endif