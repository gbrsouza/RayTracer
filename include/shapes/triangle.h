#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "shape.h"
#include "triangleMesh.h"

#include "../common.h"
#include "../ray.h"
#include "../surfaceInteraction.h"
#include "../src/vec3.cpp"

class Triangle : public Shape {

private:

        /**
         * @brief Pointer to an index array stored elsewhere (triangle mesh) in memory. 
         * After the proper triangle initialization, we may access v[0], v[1], and v[2]
         */
        int *v; 
        
        std::shared_ptr<TriangleMesh> mesh;
        
        bool backface_cull; // Set it `true` to turn backface culling.

public:
        Triangle( Material * material,
                  std::shared_ptr<TriangleMesh> mesh, 
                  int tri_id, 
                  bool bfc = true )
            : Shape{material}, mesh{mesh}, backface_cull{bfc}

        { v = &mesh->vertexIndices[ 3 * tri_id ]; }  
       
        bool intersect(
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
        
        bool intersect_p( const Ray &ray ) const
        {
            return this->intersect(ray, nullptr);
        }

        /**
         * @brief get vertices 
         */
        void vertices ( 
            point3 &p1, 
            point3 &p2, 
            point3 &p3 ) 
        const
        {
            p1 = mesh->points[v[0]];
            p2 = mesh->points[v[1]];
            p3 = mesh->points[v[2]];
        }

        /**
         * @brief get normals
         */
        void normals(
            vector &n1,
            vector &n2, 
            vector &n3) 
        const 
        {
            n1 = mesh->normals[v[0]];
            n2 = mesh->normals[v[1]];
            n3 = mesh->normals[v[2]];
        }

        // Return the triangle's bounding box.
        Bounds3 bounding_box () const override {
            point3 &p1, &p2, &p3;
            vertices( p1, p2, p3);
            auto bounds = Bounds3{p1, p2};

            return bounds.get_union(bounds, p3);
        } 

};

#endif