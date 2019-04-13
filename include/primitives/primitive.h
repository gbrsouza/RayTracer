#ifndef _PRIMITIVE_H_
#define _PRIMITIVE_H_

#include "../common.h"
#include "../ray.h"

/**
 * @brief An abstract class Primitive that represents any surface that might be
 * hit by a ray. Any class derived from Primitive should provide method to
 * determine intersection of a ray with the object as well as return a pointer
 * to the material object associated with the object (not necessary for now).
 */
class Primitive {

public:
    virtual ~Primitive();
    //virtual bool intersect (const Ray& r, SurfaceInteraction *) const = 0;
    /**
     * @brief  check if a ray intersect a primitive
     * 
     * @param r        the ray 
     * @return true    if the ray intersect the sphere 
     * @return false   if the ray not intersect the sphere
     */
    virtual bool intersect_p(Ray& r) const = 0;
    //virtual const Material * get_material(void) const = { return material; }

private: 
   // std::shared_ptr<Material> material;
};

#endif