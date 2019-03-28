#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "vec3.h"

typedef Vec3 Ray;
typedef Vec3 Color;

class Background {

private:

    //<! The background colors
    Color colors[4]; 

public:

    /**
     * @brief Construct a new Background object.
     *        Use to define a solid color in background
     * 
     * @param c1  The background color
     */
    Background(const Color& c1) 
    { colors[0] = c1; colors[1] = c1;
      colors[2] = c1; colors[3] = c1;}

    /**
     * @brief Construct a new Background object.
     *        Use to define a background with two color
     *        interpolation
     * 
     * @param c1  The first color
     * @param c2  The second color
     */
    Background(const Color& c1, const Color& c2)
    { colors[0] = c1; colors[1] = c1;
      colors[2] = c2; colors[3] = c2;}

    /**
     * @brief Construct a new Background object.
     *        Use to define a background with bilinear 
     *        interpolation
     * 
     * @param c1  The color 1 
     * @param c2  The color 2
     * @param c3  The color 3
     * @param c4  The color 4
     */
    Background(const Color& c1, const Color& c2, 
               const Color& c3, const Color& c4)
    { colors[0] = c1; colors[1] = c2; 
      colors[2] = c3; colors[3] = c4; }
 
    Color sample (float i, float j);

};

#endif