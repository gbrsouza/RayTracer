#ifndef _GEOMETRIC_PRIMITIVE_H_
#define _GEOMETRIC_PRIMITIVE_H_

/**
 * @file geometricPrimitive.h
 * @author Gabriel Araújo de Souza (gabriel_feg@hotmail.com)
 * @brief  The implementation of Primitive class
 * @version 0.1
 * @date 2019-05-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "primitive.h"
#include "common.h"
#include "../shapes/shape.h"
#include "../materials/material.h"

/**
 * @brief  implements the Primitive interface and, 
 * as the name implies, represents a geometric object.
 */
class GeometricPrimitive : public Primitive {

private:

    std::shared_ptr<Shape> shape;       //<! The shape that this class represents
    std::shared_ptr<Material> material; //<! The material of primitive

public:

    /**
     * @brief Construct a new Geometric Primitive object
     * 
     * @param shape    The pointer to a shape
     * @param material The pointer to a material
     */
    GeometricPrimitive ( std::shared_ptr<Shape> shape,
                         std::shared_ptr<Material> material)
                       : shape{shape}, material{material} {}

    /**
     * @brief Destroy the Geometric Primitive object
     */
    ~GeometricPrimitive(){ /* Empty */ }

    // @Override
    bool intersect ( const Ray& r,
                     SurfaceInteraction * surface)
                     const
    { return shape->intersect(r, surface); }

    // @Override
    bool intersect_p( const Ray& r ) const 
    { return shape->intersect_p(r); }

    // @Override
    Bounds3 bounding_box () const 
    { return shape->bounding_box(); }

    /**
     * @brief Get the material object
     * @return std::shared_ptr<Material> the material 
     */
    std::shared_ptr<Material>
    get_material()
    { return this->material; }

};


#endif