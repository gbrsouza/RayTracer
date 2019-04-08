#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "ray.h"

class Camera {

private:

    int width;  //<! Width of camera 
    int height; //<! height of camera

public:

    /**
     * @brief Construct a new Camera object
     * 
     * @param width   the width of camera
     * @param height  the height of camera
     */
    Camera (int width, int height) 
    : width{width}, height{height} {/*empty*/} 

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