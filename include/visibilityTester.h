#ifndef _VISIBILITY_TESTER_
#define _VISIBILITY_TESTER_

/**
 * @file visibilityTester.h
 * @author Gabriel Araújo de Souza (gabriel_feg@hotmail.com)
 * @brief  a class for test unoccluded 
 * @version 0.1
 * @date 2019-05-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#include "surfaceInteraction.h"
#include "scene.h"
#include "ray.h"

class Scene;

/**
 * @brief class for shoot a shadowray
 */
class VisibilityTester {

private:
    SurfaceInteraction p0;  // point 0
    SurfaceInteraction p1;  // point 1

public:

    /**
     * @brief Construct a new Visibility Tester object
     * 
     * @param p0 the point 0
     * @param p1 the point 1
     */
    VisibilityTester(
        SurfaceInteraction p0,
        SurfaceInteraction p1) 
        : p0{p0}, p1{p1} {}

    /**
     * @brief Destroy the Visibility Tester object
     */
    ~VisibilityTester(){}

    /**
     * @brief shoot a shandow ray searching bi
     * unoccluded
     * 
     * @param scene   The scene 
     * @return true   If is unoccluded
     * @return false  otherwise
     */
    bool unoccluded(const Scene &scene);

    /**
     * @brief shoot a ray of p0 to p1
     * @return Ray 
     */
    Ray shoot_ray() const;

};


#endif