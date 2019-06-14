#include "shapes/triangle.h"
#include "ray.h"
#include "../vec3.cpp"

bool Triangle::intersect(
            const Ray &r,
            SurfaceInteraction *surface 
        ) const
{
    const float EPSILON = 0.000001;
    point3 &v1, &v2, &v3;
    vertices(v1, v2, v3);

    vector edge1, edge2, h, s, q;
    float a,f,u,v;

    edge1 = v2 - v1;
    edge2 = v3 - v2; 

    const auto &origin_ray = r.get_origin();
    const auto &direction_ray = unit_vector(r.get_direction());

    h = cross(direction_ray, edge2);
    a = dot(edge1, h);

    point2f uv;
    float * tHit;

    if (bfc){
        if (a < EPSILON)
            return false;
        
        s = origin_ray - v1;
        u = ( dot(s,h) );
    
        if ( u < 0.0 || u > 1.0)
            return false;

        uv.element[0] = u;

        q = cross(s, edge1);
        v = dot(direction_ray, q);
    
        if ( v < 0.0 || (u + v) > a )
            return false;
        
        uv.element[1] = v;

        *tHit = dot(edge2, q);
        f = 1.0/a;
        *tHit *= f;
        uv *= f;

        if ( tHit < EPSILON )
            return false;

    }else {
        // check if the ray is parallel to this triangle
        if ( a > -EPSILON && a < EPSILON )
            return false;
        
        f = 1.0/a;
        s = origin_ray - v1;
        u = f * ( dot(s,h) );

        if ( u < 0.0 || u > 1.0)
            return false;
        
        uv.element[0] = u;

        q = cross(s, edge1);
        v = f * dot(direction_ray, q);

        if ( v < 0.0 || (u + v) > 1.0 )
            return false;

        uv.element[1] = v;

        *tHit = f * dot(edge2, q)

        if ( *tHit < EPSILON ){
            return false;
    }

    if (*tHit > ray.tMax)
        return false;
    
    if ( surface != nullptr ){
        surface->p = ray(*tHit);
        surface->uv = uv;
        surface->wo = -1.0 * r.get_direction();
        surface->t = *tHit;

        vector &n1, &n2, &n3;
        normals(n1, n2, n3);

        surface->n = unit_vector(
            (1 - uv.element[0] - uv.element[1] * n1 
                + uv.element[0] * n2 + uv.element[1] * n2);
    }

    return true;

}

bool Triangle::intersect_p( const Ray &ray ) const
{
    return this->intersect(ray, nullptr);
}

// Return the triangle's bounding box.
Bounds3 Triangle::bounding_box () const {
    point3 &p1, &p2, &p3;
    vertices( p1, p2, p3);
    auto bounds = Bounds3{p1, p2};

    return bounds.get_union(bounds, p3);
} 