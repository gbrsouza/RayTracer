#ifndef _RASTER_H_
#define _RASTER_H_

#include "canvas.h"
#include <fstream>
#include <iostream>

/**
 * @brief the class for raster
 * 
 */
class Raster {

private:
	Canvas * canvas; //<! the canvas

	std::string filename = "out"; //<! file name

public:

	/**
	 * @brief      Constructs the object.
	 *
	 * @param      canvas  The canvas
	 */
	Raster (Canvas * canvas);

	/**
	 * @brief      Constructs the object.
	 *
	 * @param      canvas    The canvas
	 * @param[in]  filename  The filename
	 */
	Raster (Canvas * canvas, std::string filename);

	/**
	 * @brief      draw canvas
	 */
	void draw ();

};

#endif