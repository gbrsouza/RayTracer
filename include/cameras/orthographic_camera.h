#ifndef _ORTHOGRAPHIC_CAMERA_H
#define _ORTHOGRAPHIC_CAMERA_H

#include "camera.h"

/**
 * @brief A class for a orthographic camera,
 * this is a child of Camera class
 * 
 */
class OrthographicCamera : public Camera {

private:

    //<! View plane dimensions 
    //<! [left, right, bottom and up]
    float l, r, b, t;   

public: 

    /**
     * @brief Construct a new Orthographic Camera object
     * 
     * @param film      the camera's film
     * @param position  the camera's position
     * @param target    the camera's target (-Z axis)
     * @param upVector  the camera's up vector
     * @param l         the left view plane dimension
     * @param r         the right view plane dimension
     * @param b         the bottom view plane dimension
     * @param t         the top view plane dimension
     */
    OrthographicCamera( std::shared_ptr<Film> film, 
                        point3 &position, point3 &target,
                        Vec3 &vUp, float l, float r,
                        float b, float t) 

            : Camera {position, target, vUp, film},
              l{l}, r{r}, b{b}, t{t} {}

    /**
     * @brief Destroy the Orthographic Camera object
     */
    ~OrthographicCamera(){/*empty*/}

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