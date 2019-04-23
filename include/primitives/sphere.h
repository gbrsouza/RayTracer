#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "primitive.h"
#include "surfaceInteraction.h"
#include "../src/vec3.cpp"
#include "common.h"
#include <cmath>

class Sphere : public Primitive {

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

    ~Sphere(){};

    #include <iostream>
    //Override
    bool intersect (const Ray& r, SurfaceInteraction * surface) const{

        point3 origin = r.get_origin();
        vector direction = r.get_direction();

        vector oc = origin - this->center;

        float a = dot(direction, direction);
        float b = 2.0 * dot(oc, direction);
        float c = dot(oc,oc) - (this->radius * this->radius);
        
        float delta = (b * b) - (4.0 * a * c);

        // std::cout << "origin: " << origin << std::endl;
        // std::cout << "center: " << center << std::endl;
        // std::cout << "oc: " << origin - center << std::endl; 
        // std::cout << "dot(oc, dir): " << dot(oc, direction) << std::endl;
        // std::cout << "a: " << a << std::endl;
        // std::cout << "b: " << b << std::endl;
        // std::cout << "c: " << c << std::endl;
        // std::cout << "delta: " << delta << std::endl;
        // std::cout << r << std::endl;

        if (delta < 0.0) return false;

        float r1 = (-b + sqrt(delta)) / (2 * a);
        float r2 = (-b - sqrt(delta)) / (2 * a);

        surface->p = r(fmin(r1,r2));

        return true;
    }

    // Override
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