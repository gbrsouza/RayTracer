#ifndef _SURFACE_INTERACTION_H_
#define _SURFACE_INTERACTION_H_

#include "common.h"
#include "primitives/primitive.h"


/**
 * @brief The class SurfaceInteraction represents the geometry of particular point
 * on a surface (often a position found by intersecting a ray against the surface).
 * This abstraction allows us to pass the contact information along to other
 * parts of the renderer without necessary having to know which object has
 * been hit.
 */
class SurfaceInteraction {

public:

    /**
     * @brief Construct a new Surface Interaction object
     * 
     * @param p     the contact point
     * @param n     the surface normal
     * @param wo    outgoing direction of light, which is -ray
     * @param time  time of contact
     * @param uv    parametric coordinate (u,v) of the hit surface
     * @param pri   pointer to the primitive
     */
    SurfaceInteraction( const point3&p, const vector&n, const vector&wo,
                        float time, const point2f uv, const Primitive *pri)
                    :   p{p}, n{n}, wo{wo}, time{time}, uv{uv}, 
                        primitive{pri} 
                    { /* empty */ };

    SurfaceInteraction (){}

    point3 p;    //<! contact point
    vector n;    //<! the surface normal
    vector wo;   //<! outgoing direction of light, which is -ray
    float time;  //<! time of contact
    point2f uv;  //<! parametric coordinate (u,v) of the hit surface
    const Primitive *primitive = nullptr; //<! pointer to the primitive
};

#endif