#ifndef _FILM_H_
#define _FILM_H_

/**
 * @file film.h
 * @author Gabriel Araújo de Souza (gabriel_feg@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "common.h"

#include <fstream>
#include <iostream>
#include <string>

class Film {

private:
    
    Point2i dimensions;    //<! The image dimensions
    uint * image;          //<! all pixels of image
    std::string filename;  //<! The image's name
    std::string extension; //<! The image's extension

public:
    
    /**
     * @brief Construct a new Film object
     * 
     * @param width     The x axis of image dimension
     * @param heigth    The y axis of image dimension
     * @param filename  The image's name
     * @param extension The image's extension
     */
    Film( int width,
          int heigth,
          std::string filename,
          std::string extension)
        
        : dimensions{Point2i(width, heigth, 0)},
          image{new uint[width * heigth * VALUES_PER_PIXEL]},
          filename{filename},
          extension{extension}{}

    /**
     * @brief Construct a new Film object
     * 
     * @param dimensions  The image dimensions
     * @param image       all pixels of image
     */
    Film ( Point2i dimensions,
           uint * image )
        : dimensions{dimensions}, image{image}{}

    /**
     * @brief Destroy the Film object
     */
    ~Film(){ /*empty*/ }

    /**
     * @brief  Color a pixel in image
     * 
     * @param pixel  The pixel
     * @param color  The pixel's color
     */
    void add_sampler( Point2i pixel, 
                      Color24 color);

    /**
     * @brief save the image
     */
    void write_img();

    /**
     * @brief Get the size object
     * @return int The size of image array
     */
    uint get_size()
    { return dimensions.x() * dimensions.y() * VALUES_PER_PIXEL; }

    /**
     * @brief Get the dimension object
     * @return Point2i the dimensions of image
     */
    Point2i get_dimension()
    { return this->dimensions; }

    /**
     * @brief Get the position pixel object
     * 
     * @param x  the x axis of a pixel
     * @param y  the y axis of a pixel
     * @return int  The pixel position of a image array
     */
    int get_position_pixel(int x, int y);

    /**
     * @brief Get the filename object
     * @return std::string  the filename
     */
    std::string get_filename()
    { return this->filename; }
};

#endif