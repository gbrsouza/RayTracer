#ifndef _AGGREGATE_PRIMITIVE_H_
#define _AGGREGATE_PRIMITIVE_H_

/**
 * @file aggregatePrimitive.h
 * @author Gabriel Araújo de Souza (gabriel_feg@hotmail.com)
 * @brief  The implementation of aggregate primitive class
 * @version 0.1
 * @date 2019-05-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "common.h"
#include "primitive.h"
#include <vector>

/**
 * @brief implements the Primitive interface but stores 
 * a container of other primitives. Usually this container
 * is an acceleration data structure, such as BVH or K-d 
 * tree. In this project, this is just a list of geometric 
 * primitives.
 */
class AggregatePrimitive : public Primitive {

private: 

    //<! The container of primitives
    std::vector<std::shared_ptr<Primitive>> primitives; 

public:

    /**
     * @brief Construct a new Aggregate Primitive object
     * 
     * @param primitives The container of primitives
     */
    AggregatePrimitive( std::vector<std::shared_ptr<Primitive>> primitives )
                    :   primitives{primitives} {}

    /**
     * @brief Destroy the Aggregate Primitive object
     */
    ~AggregatePrimitive(){ /* Empty */ }

     // @Override
    bool intersect ( const Ray& r,
                     SurfaceInteraction * surface)
                     const
    {
        for ( const auto p : primitives )
            p->intersect( r, surface );
    }

    // @Override
    bool intersect_p( const Ray& r ) const { 
        for ( const auto p : primitives )
            p->intersect_p( r );
    }

};

#endif
