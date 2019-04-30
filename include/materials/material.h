#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "../common.h"

class SurfaceInteraction;

class Material{

public:

    /**
     * @brief Destroy the Material object
     */
    virtual ~Material();

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