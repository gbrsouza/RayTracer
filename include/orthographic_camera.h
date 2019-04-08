#ifndef _ORTHOGRAPHIC_CAMERA_H
#define _ORTHOGRAPHIC_CAMERA_H

#include "camera.h"

class OrthographicCamera : public Camera {

private:
    point3 position;  //<! located at the origin
    point3 target;    //<! looking down the -Z axis
    Vec3 upVector;    //<! the camera's up vector

    //<! View plane dimensions 
    //<! [left, right, bottom and up]
    float l, r, b, t;   

public: 

    /**
     * @brief Construct a new Orthographic Camera object
     * 
     * @param w         the width of camera
     * @param h         the height of camera
     * @param position  the camera's position
     * @param target    the camera's target (-Z axis)
     * @param upVector  the camera's up vector
     * @param l         the left view plane dimension
     * @param r         the right view plane dimension
     * @param b         the bottom view plane dimension
     * @param t         the top view plane dimension
     */
    OrthographicCamera( int w, int h, point3 &position,
        point3 &target, Vec3 &upVector, float l, float r,
        float b, float t) 
        
        : Camera(w,h), position{position}, target{target},
          upVector{upVector}, l{l}, r{r}, b{b}, t{t}
    {/*empty*/}

    ~OrthographicCamera(){/*empty*/}

    Ray generate_ray(int x, int y);

};

#endif