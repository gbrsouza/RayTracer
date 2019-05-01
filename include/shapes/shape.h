#ifndef _SHAPE_H_
#define _SHAPE_H_

/**
 * @file shape.h
 * @author Gabriel Araújo de Souza (gabriel_feg@hotmail.com)
 * @brief  a interface to represent a shape 
 * @version 0.1
 * @date 2019-04-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "common.h"

/**
 * @brief It is the base class for all geometric shapes,
 * such as triangles, spheres, planes, disks, etc.
 */
class Shape {

public:

    /**
     * @brief Destroy the Shape object
     */
    ~Shape(){}

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

    /**
     * @brief Set the id object
     * @param id the new id
     */
    void set_id ( int id ) { this->id = id; }

protected:

    int id; //<! The shape id

 

};

#endif