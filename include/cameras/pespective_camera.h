#ifndef _PESPECTIVE_CAMERA_H_
#define _PESPECTIVE_CAMERA_H_

#include "camera.h"

class PespectiveCamera : public Camera {

private:

    float fovy;      //<! The vertical field of view
    float aspect;    //<! Optional parameter, aspect ration W/H
    float fdistance; //<! The focal distance

public:

    /**
     * @brief Construct a new Pespective Camera object
     * 
     * @param w         the width
     * @param h         the height
     * @param position  the position of camera
     * @param target    the target of camera
     * @param vUp       the up vector
     * @param fovy      The vertical field of view
     * @param aspect    Optional parameter, aspect ration W/H
     * @param fdistance The focal distance
     */
    PespectiveCamera( std::shared_ptr<Film> film, 
                      point3 &position, point3 &target,
                      Vec3 &vUp, float fovy, 
                      float aspect, float fdistance)

            : Camera{position, target, vUp, film},
              fovy{fovy}, aspect{aspect}, 
              fdistance{fdistance} {}

    // /**
    //  * @brief Construct a new Pespective Camera object
    //  * from other camera
    //  * @param c the camera
    //  */
    // PespectiveCamera( PespectiveCamera *& c )
    //     : Camera{*c}, fovy{c->fovy}, aspect{c->aspect},
    //       fdistance{c->fdistance} {}

    /**
     * @brief Destroy the Pespective Camera object
     */
    ~PespectiveCamera(){/*empty*/}

    /**
     * @brief Generate a ray in the orthographic camera 
     * for the params x and y.
     * 
     * @param x  the pixel's x axis
     * @param y  the pixel's y axis
     * @return Ray  the ray in the pixel
     */
    Ray generate_ray(int x, int y);
};

#endif