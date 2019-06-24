#ifndef _TRIANGLE_MESH_H
#define _TRIANGLE_MESH_H

#include <vector>
#include "common.h"

struct TriangleMesh {
    
    const int nTriangles; //!< # of triangles in the mesh.
    const int nVertices;

    // The size of the list below should be 3 * nTriangles. Every 3 values we have a triangle.
    std::vector< int > vertexIndices; //!< The list of indices that make up each individual triangle.

    // He comes the data associated with each vertex.
    std::unique_ptr< point3[] > points;   //!< The 3D geometric coordinates
    std::unique_ptr< vector[] > normals; //!< The 3D normals.
    std::unique_ptr< point2f[] > uv;       //!< The 2D texture coordinages (might be 3D, if necessary).

    // Regular constructor
    TriangleMesh( int nTri, 
                  const int *indices,
                  int nVertices, 
                  const point3 *p,
                  const vector *n, 
                  const point2f *uv )
        : nTriangles{nTri}, nVertices{nVertices},
          vertexIndices{indices, indices + 3 * nTri}
        {
            points.reset(new point3[nVertices]);
            for (int i = 0; i < nVertices; i++)
                points[i] = p[i];
            
            normals.reset(new vector[nVertices]);
            for (int i = 0; i < nVertices; i++)
                normals[i] = n[i];
            
            UNUSED(uv);
            //uv.reset( new point2f[])

        }
          

};

#endif