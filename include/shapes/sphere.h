#ifndef _SPHERE_H_
#define _SPHERE_H_

/**
 * @file sphere.h
 * @author Gabriel Araújo de Souza (gabriel_feg@hotmail.com)
 * @brief It implements the Shape class to represent a sphere
 * @version 0.1
 * @date 2019-04-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "shape.h"
#include "../surfaceInteraction.h"
#include "../src/vec3.cpp"

#include <cmath>

class Sphere : public Shape {

private:

    point3 center;  //<! the center of sphere
    float radius;   //<! the radius of sphere

public:
    /**
     * @brief Construct a new Sphere object
     * 
     * @param center   the center of sphere
     * @param radius   the radius of sphere
     */
    Sphere (const point3 &center, float radius)
    : center{center}, radius{radius} {};

    /**
     * @brief Destroy the Sphere object
     */
    ~Sphere(){};

    // @Override
    bool intersect ( const Ray& r, 
                     SurfaceInteraction * surface) 
                     const
    {

        point3 origin = r.get_origin();
        vector direction = r.get_direction();

        vector oc = origin - this->center;

        float a = dot(direction, direction);
        float b = 2.0 * dot(oc, direction);
        float c = dot(oc,oc) - (this->radius * this->radius);
        
        float delta = (b * b) - (4.0 * a * c);

        if (delta < 0.0) return false;

        float r1 = (-b + sqrt(delta)) / (2 * a);
        float r2 = (-b - sqrt(delta)) / (2 * a);

        surface->p = r(fmin(r1,r2));

        return true;
    }

    // @Override
    bool intersect_p(const Ray& r) const
    {
        auto origin = r.get_origin();
        auto direction = r.get_direction();
        
        vector oc = origin - this->center;
        float a = dot(direction, direction);
        float b = 2.0 * dot(oc, direction);
        float c = dot(oc,oc) - (this->radius * this->radius);
        
        float delta = b * b - 4.0 * a * c;         
        return (delta >= 0.0);
    }

};

#endif