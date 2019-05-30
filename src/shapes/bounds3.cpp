#include "shapes/bounds3.h"
#include "../vec3.cpp"

Bounds3
Bounds3::expand(const Bounds3 &b, float delta) {
    return Bounds3(b.pMin - vector(delta, delta, delta),
                    b.pMax + vector(delta, delta, delta));
}

vector 
Bounds3::diagonal() const 
{ return pMax - pMin; }

float 
Bounds3::surface_area() const {
    vector d  = diagonal();
    return 2 * (d.x() * d.y() + d.x() * d.z() + d.y() * d.z());
}

float 
Bounds3::volume () const {
    vector d = diagonal();
    return d.x() * d.y() * d.z(); 
}

int 
Bounds3::maximum_extent() const {
    vector d = diagonal();
    if (d.x() > d.y() && d.x() > d.z())
        return 0;
    else if (d.y() > d.z())
        return 1;
    else return 2;
}

vector 
Bounds3::offset( const point3 &p ) const {
    
    vector o = p - pMin;
    
    if (pMax.x() > pMin.x()) o[0] /= pMax.x() - pMin.x();
    if (pMax.y() > pMin.y()) o[1] /= pMax.y() - pMin.y();
    if (pMax.z() > pMin.z()) o[2] /= pMax.z() - pMin.z();
    return o;
}

/**
 * ---------------------------------
 * specific bounding box to shapes +
 * ---------------------------------
 */

void 
Bounds3::bounding_to_sphere ( 
    point3 *center, float *radius )
{
    *center = (pMin + pMax) / 2;
    if ( inside(*center, *this) ) *radius = distance(pMax, *center);
    else * radius = 0;

}