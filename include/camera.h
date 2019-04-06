#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "ray.h"

class Camera {

protected:
    Ray generate_ray(int x, int y);

};

#endif