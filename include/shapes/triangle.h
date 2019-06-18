#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "shape.h"
#include "triangleMesh.h"
#include "../surfaceInteraction.h"


#include <tuple>

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
                  bool backface_cull = true )
            : Shape{material}, mesh{mesh}, backface_cull{backface_cull}

        { v = &mesh->vertexIndices[ 3 * tri_id ]; }  
       
        bool intersect(
            const Ray &r,
            SurfaceInteraction *surface 
        ) const;
        
        
        bool intersect_p( 
            const Ray &ray 
        ) const;
    

        /**
         * @brief get vertices 
         */
        std::tuple<point3, point3, point3> 
        vertices () const
        {
            auto &p1 = mesh->points[v[0]];
            auto &p2 = mesh->points[v[1]];
            auto &p3 = mesh->points[v[2]];

            return std::make_tuple(p1,p2,p3);
        }

        /**
         * @brief get normals
         */
        std::tuple<vector, vector, vector> 
        normals() const 
        {
            auto &n1 = mesh->normals[v[0]];
            auto &n2 = mesh->normals[v[1]];
            auto &n3 = mesh->normals[v[2]];

            return std::make_tuple(n1,n2,n3);
        }

        // Return the triangle's bounding box.
        Bounds3 bounding_box () const override ;

};


#endif