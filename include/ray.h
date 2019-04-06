#ifndef _RAY_H_
#define _RAY_H_

#include "common.h"


class Ray {

private:
    point3 o ; //<! origin point
    Vec3 d;    //<! direction

public:

    /**
     * @brief Construct a new Ray object
     * 
     * @param o The origin point
     * @param d The distance of ray
     */
    Ray (const point3& o, const Vec3& d ) 
    : o{o}, d{d} {/*empty*/ }

    /**
     * @brief overloading for operator ()
     * 
     * @param t  a parameter for the ray
     * @return Vec3  o + t*d
     */
    Vec3 operator() (float t);
};

#endif