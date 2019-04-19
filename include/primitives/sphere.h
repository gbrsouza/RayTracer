#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "primitive.h"
#include "../src/vec3.cpp"
#include "common.h"

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
    Sphere (point3 &center, float radius)
    : center{center}, radius{radius} {};

    ~Sphere(){};

    // Override
    bool intersect_p(Ray& r)
    {
        vector oc = r.get_origin() - this->center;
        float a = dot(r.get_direction(), r.get_direction());
        float b = 2.0 * dot(oc, r.get_direction());
        float c = dot(oc,oc) - radius*radius;
        float discriminant = b*b - 4*a*c;
        return (discriminant > 0);
    }


};

#endif