#ifndef _DIRECTIONAL_LIGHT_
#define _DIRECTIONAL_LIGHT_

#include "light.h"

class DirectionalLight : public Light {

private:
    point3 direction; //<! light's direction

public:

    /**
     * @brief Construct a new Directional Light object
     * 
     * @param intensity the light's intensity 
     * @param direction the light's direction
     */
    DirectionalLight( 
        point3 intensity,
        point3 direction)
    : Light{intensity}, 
      direction{direction}
      {}
    
    /**
     * @brief Destroy the Directional Light object
     */
    ~DirectionalLight(){/*empty*/}

    // Override
    Vec3 Li(
        const SurfaceInteraction &isect,
        vector *wi,
        VisibilityTester *vt) const;

    /**
     * @brief Get the direction object
     * @return point3 the direction
     */
    point3 get_direction(){ return direction; }

};

#endif