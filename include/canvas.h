#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <iostream>
#include <vector>

#include "color.h"
#include "common.h"
#include "vec3.h"

typedef unsigned int uint;

/**
 * @brief The Canvas class
 * 
 */
class Canvas {

private:
	
	uint m_width;       //<! width of image
	uint m_heigth;      //<! height of image
	color_t * image;    //<! image representation (a array of unsigned int)

public:

	/**
	 * @brief      Constructs the object.
	 *
	 * @param[in]  m_width   The width
	 * @param[in]  m_heigth  The heigth
	 */
	Canvas (unsigned int m_width = 800, unsigned int m_heigth = 600);

	/**
	 * @brief      Destroys the object.
	 */
	~Canvas ();

	/**
	 * @brief      Constructs the object.
	 *
	 * @param      clone  The clone
	 */
	Canvas (Canvas && clone);

	/**
	 * @brief the overload of assignment operator
	 *  
	 * @param rhs  the new Canvas
	 * @return Canvas&  A new Canvas equals rhs
	 */
	Canvas& operator= (const Canvas & rhs);

	/**
	 * @brief      add a color in a pixel
	 *
	 * @param[in]  x  The x axis of a pixel
	 * @param[in]  y  The y axis of a pixel
	 * @param      color   The pixel color 
	 */
	void color_pixel (int x, int y, Color &color);

	void color_pixel (int x, int y, Vec3 &color);

	/**
	 * @brief      Gets the image.
	 *
	 * @return     The image.
	 */
	color_t * get_image ();

	/**
	 * @brief      Gets the width.
	 *
	 * @return     The width.
	 */
	uint get_width ();

	/**
	 * @brief      Gets the heigth.
	 *
	 * @return     The heigth.
	 */
	uint get_heigth ();

	/**
	 * @brief      Gets the size canvas.
	 *
	 * @return     The size canvas.
	 */
	uint get_size_canvas ();

	/**
	 * @brief Get the position pixel object
	 * 
	 * @param x the x axis
	 * @param y the y axis
	 * @return int the pixel's position in image array
	 */
	int get_position_pixel(int x, int y);

};

#endif