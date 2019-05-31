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
#include <limits>

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
        bool v;
        for ( const auto p : primitives ){
            v = p->intersect( r, surface );
            if ( v ) return true; 
        }

        return false;

        // bool v = false;
        // float t_min = std::numeric_limits<float>::max();
        // SurfaceInteraction *surface_min; 
        
        // // get the min point isect;
        // for ( const auto p : primitives ){
        //     // std::cout << "oi\n";
        //     v = p->intersect( r, surface );
        //     if ( surface->t < t_min ) {
        //         t_min = surface->t;
        //         surface_min = surface;
        //     }
        // }

        // surface = surface_min;
    
        // return v;
    }

    // @Override
    bool intersect_p( const Ray& r ) const { 
        bool v;
        for ( const auto p : primitives ){
            v = p->intersect_p( r );
            if (v) return true;
        }
        return false;            
    }



    inline Bounds3 bounding_box () const override{
        Bounds3 world_bound = primitives[0]->bounding_box();
        for ( const auto p : primitives ){
            world_bound = world_bound.get_union( world_bound, p->bounding_box() );
        }
        // std::cout << " word_bound: \n pMin" << world_bound.pMin << " \npMax " << world_bound.pMax << std::endl;  
        return world_bound;

    }

};

#endif
