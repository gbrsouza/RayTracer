#ifndef _SHAPE_H_
#define _SHAPE_H_

/**
 * @file shape.h
 * @author Gabriel Araújo de Souza (gabriel_feg@hotmail.com)
 * @brief  a interface to represent a shape 
 * @version 0.1
 * @date 2019-04-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "common.h"

/**
 * @brief It is the base class for all geometric shapes,
 * such as triangles, spheres, planes, disks, etc.
 */
class Shape {

public:

    /**
     * @brief Destroy the Shape object
     */
    virtual ~Shape();


};

#endif