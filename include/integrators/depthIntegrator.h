#ifndef _DEPTH_INTEGRATOR_H_
#define _DEPTH_INTEGRATOR_H_

#include "samplerIntegrator.h"

/**
 * @brief The color associated with a hit is calculated
 * as follow: normalize the depth hit in [Zmin,Zmax] and 
 * use this normalized value to linearly interpolate a 
 * color between white and black. This approach produces
 * a gray scale image representing the depth map of the 
 * scene.
 */
class DepthIntegrator : public SamplerIntegrator {

public:

    /**
     * @brief Construct a new Depth Integrator object
     * 
     * @param cam      The camera
     * @param sampler  The sampler   
     */
    DepthIntegrator( std::shared_ptr<Camera> cam,
                     std::shared_ptr<Sampler> sampler,
                     Color24 near,
                     Color24 far)
        : SamplerIntegrator{cam, sampler},
          near_color{near}, far_color{far} {}

    // @Override
    void 
    preprocess( const Scene& scene );

    // @Override
    Color24 
    Li( const Ray& ray,
        const Scene& scene,
        Sampler& sampler ) const;

private:
    Color24 near_color;  //<! The near color
    Color24 far_color;   //<! The far color

};

#endif