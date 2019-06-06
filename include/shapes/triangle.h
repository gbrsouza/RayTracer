#ifndef _TRIANGLE_H_
#define  _TRIANGLE_H_

#include "shape.h"
#include "common.h"
#include "triangleMesh.h"

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
        Triangle( Material * material
                  std::shared_ptr<TriangleMesh> mesh, 
                  int tri_id, 
                  bool bfc = true )

            : Shape(material), mesh{mesh}, backface_cull{bfc}

        { v = &mesh->vertexIndices[ 3 * tri_id ]; }
       
        // Return the triangle's bounding box.
        Bounds3 object_bound() const;
       
        bool intersect( const Ray &ray, float *thit, SurfaceInteraction *isect ) const;
        
        bool intersect_p( const Ray &ray ) const;

};

#endif