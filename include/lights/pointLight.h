#ifndef _POINT_LIGHT_
#define _POINT_LIGHT_

#include "light.h"

class PointLight : public Light { 

private:
    
    

public:
    point3 position; // the light's position
    
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
    : Light{intensity}, position{position} {}

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