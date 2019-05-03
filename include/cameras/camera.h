#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "ray.h"
#include "../film.h"
#include "../common.h"

class Camera {

protected:

    int width;                  //<! Width of camera 
    int height;                 //<! height of camera
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
     * @brief Destroy the Camera object
     */
    ~Camera(){/*empty*/}

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
     * @brief Get the width object
     * @return int  the width value
     */
    int get_width (){return width;}

    /**
     * @brief Get the height object
     * @return int The height value
     */
    int get_height (){return height;}
};

#endif