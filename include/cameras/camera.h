#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "ray.h"
#include "../film.h"
#include "../common.h"

class Camera {

protected:

    point3 position;            //<! located at the origin
    point3 target;              //<! looking down the -Z axis
    Vec3 vUp;                   //<! the camera's up vector
    std::shared_ptr<Film> film; //<! The camera's film 

public:

    /**
     * @brief Construct a new Camera object
     * 
     * @param position  the camera's position
     * @param target    the camera's target (-Z axis)
     * @param vUp       the camera's up vector
     * @param film      the camera's film
     */
    Camera ( point3 position, 
             point3 target,
             Vec3 vUp,
             std::shared_ptr<Film> film)
        
        :   position{position}, target{target},
            vUp{vUp}, film{film} {}

    /**
     * @brief Construct a new Camera object from other 
     * Camera
     * @param c a Camera
     */
    // Camera ( Camera *&c )
    //     : position{c->position},
    //       target{c->target},
    //       vUp{c->vUp},
    //       film{c->film}{}
    
    /**
     * @brief Destroy the Camera object
     */
    virtual ~Camera(){/*empty*/}

    /**
     * @brief generate a ray based in a coordenates x and y.
     * Each camera implements the own method
     * 
     * @param x   the x value
     * @param y   the y value
     * @return Ray  The ray in x,y pixel. 
     */
    virtual Ray generate_ray(int x, int y)
    { return Ray(point3(x,y,1), Vec3(x,y,1)); }

    /**
     * @brief Get the film object
     * 
     * @return std::shared_ptr<Film> the camera's film
     */
    std::shared_ptr<Film> get_film ()
    { return this->film; }

    /**
     * @brief Get the width object
     * @return int the value of width
     */
    int get_width ()
    { return this->film->get_dimension().x(); }

    /**
     * @brief Get the heigth object
     * @return int the value of height
     */
    int get_height ()
    { return this->film->get_dimension().y(); }


};

#endif