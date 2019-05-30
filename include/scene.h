#ifndef _SCENE_H_
#define _SCENE_H_

#include "common.h"
#include "lights/light.h"
#include "background.h"
#include "primitives/primitive.h"

#include <vector>

class Light;

/**
 * @brief This is the class that maintains the data structures 
 * that hold primitives, lights, and the background 
 */
class Scene {

public:
    // list of lights
    std::vector<std::shared_ptr<Light>> lights; 
    
    // the background object
    std::shared_ptr<Background> background; 

    Bounds3 world_bound;

private:
    // the scene graph of object, acceleration structure
    std::shared_ptr<Primitive> aggregate; 

//=== Public interface
public:
    /**
     * @brief Construct a new Scene object
     * 
     * @param ag the scene graph of object
     * @param bg the background of scene
     * @param ls the list of lights
     */
    Scene( std::shared_ptr<Primitive> ag, 
           std::shared_ptr<Background> bg,
           const std::vector<std::shared_ptr<Light>>& ls)
        :  lights{ls}, background{bg}, aggregate{ag}
        {
            // get the bounding box for all primitives
            world_bound = aggregate->bounding_box();
        }

    /**
     * @brief Determines the intersection info
     * 
     * @param r        the ray
     * @param surface  the surface 
     * @return true    if there is an intersection.
     * @return false   otherwise
     */
    bool intersect( const Ray& r, 
                    SurfaceInteraction *surface ) 
                    const
        { return aggregate->intersect(r, surface); }
    
    /**
     * @brief  A faster version that only determines whether 
     * there is an intersection or not. It doesn't calculate
     * the intersection info.
     * 
     * @param r       The ray
     * @return true   if there is an intersection.
     * @return false  otherwise
     */
    bool intersect_p( const Ray& r ) const
    { return aggregate->intersect_p( r ); }


};

#endif