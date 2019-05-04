#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "vec3.h"
#include "common.h"

typedef Vec3 Color;

class Background {

private:

    //<! The background colors
    Color colors[4]; 

public:

    Background()
    { Color c = Color(0,0,0);
      colors[0] = c; colors[1] = c;
      colors[2] = c; colors[3] = c;
    }

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
 
    /**
     * @brief overload operator =
     * 
     * @param rhs the rigth object
     */
    void operator= (const Background & rhs)
    { 
      for (uint i; i < 4; i++)
        this->colors[i] = rhs.colors[i];    
    }

    /**
     * @brief return a color of pixel in background
     * 
     * @param i  the x axis
     * @param j  the y axis
     * @return Color  the color of pixel
     */
    Color sample (float i, float j);

    /**
     * @brief  adapt to sample
     * 
     * @param p   a point 2D
     * @return Color   the color of point
     */
    Color sample ( Point2i p )
    { return sample(p.x(), p.y()); }

};

#endif