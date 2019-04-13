#ifndef _COMMON_H_
#define _COMMON_H_

#include "vec3.h"

#define MAX_COLOR_VALUE 255      //<! The max value RGB
#define MIN_COLOR_VALUE 0        //<! The min value RGB
#define VALUES_PER_PIXEL 3       //<! Dimension of image: three values (R,G,B);
#define OUTPUT_EXTENSION ".ppm"  //<! Default format image
#define OUTPUT_INDEX "P3"        //<! Default format image PPM
#define PI 3.141592              //<! Pi value
#define RADIANS 0.01745329252    //<! value of a degree in radians

typedef Vec3 Color;  //<! alias to color
typedef Vec3 point3; //<! alias to point 3D
typedef Vec3 vector; //<! alias to vector
typedef Vec3 point2f; //<! alias to parametric coordinate



#endif