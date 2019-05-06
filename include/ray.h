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
    Vec3 operator()(float t) const;

    /**
     * @brief Get the origin object
     * @return point3 the origin point of ray
     */
    point3 get_origin () const {return o;}
    
    /**
     * @brief Get the direction object
     * @return Vec3 a direction vector of ray
     */
    Vec3 get_direction () const {return d;}

    /**
     * @brief write a ray in default out
     * 
     * @param os the string
     * @param t  the ray
     * @return std::ostream& the string with the ray description 
     */
    friend std::ostream& operator<< (std::ostream &os, const Ray &t){
        os << "[o=" << t.o << ", d=" << t.d << "]";
        return os;
    }

    int x; // the x axis that generate this ray
    int y; // the y axis that generate this ray

};

#endif