#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "shape.h"
#include "triangleMesh.h"

#include "../common.h"
#include "../surfaceInteraction.h"

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
        ) const;
        
        
        bool intersect_p( 
            const Ray &ray 
        ) const;
    

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
        Bounds3 bounding_box () const override ;

};


#endif