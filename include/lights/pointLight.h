#ifndef _POINT_LIGHT_
#define _POINT_LIGHT_

#include "light.h"

class PointLight : public Light { 

private:
    point3 position; // the light's position
    point3 intensity; // the light intensity

public:
    
    /**
     * @brief Construct a new Point Light object
     * 
     * @param position   the light's position
     * @param intensity  the light's instensity
     */
    PointLight (
        point3 intensity,
        point3 position
    )
    : position{position}, intensity{intensity} {}

    /**
     * @brief Destroy the Point Light object
     */
    ~PointLight(){ /*empty*/ }

    // Override
    Vec3 Li(
        const SurfaceInteraction &isect,
        vector *wi,
        VisibilityTester *vt) const;

};

#endif