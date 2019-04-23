#ifndef _PRIMITIVE_H_
#define _PRIMITIVE_H_

#include "../common.h"
#include "../ray.h"
#include "../materials/material.h"

class SurfaceInteraction;

/**
 * @brief An abstract class Primitive that represents any surface that might be
 * hit by a ray. Any class derived from Primitive should provide method to
 * determine intersection of a ray with the object as well as return a pointer
 * to the material object associated with the object (not necessary for now).
 */
class Primitive {

private: 
   std::shared_ptr<Material> material;

public:
    ~Primitive(){};
   
    /**
     * @brief   check if a ray intersect a primitive
     * 
     * @param r        the ray
     * @param surface  the surface of primitive
     * @return true    if the ray intersect the sphere
     * @return false   if the ray not intersect the sphere
     */
    virtual bool intersect (const Ray& r, SurfaceInteraction * surface) const = 0;
   
    /**
     * @brief  check if a ray intersect a primitive
     * 
     * @param r        the ray 
     * @return true    if the ray intersect the sphere 
     * @return false   if the ray not intersect the sphere
     */
    virtual bool intersect_p(const Ray& r) const = 0;

    /**
     * @brief Get the material object
     * 
     * @return const std::shared_ptr<Material> the smart point for material 
     */
    virtual const std::shared_ptr<Material> get_material(void) const { return material; } 
    
    /**
     * @brief Set the id object
     * 
     * @param id the id object
     */
    void set_id (int id){ this->id = id;}

protected:
    int id;
};

#endif