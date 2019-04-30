#ifndef _FLAT_MATERIAL_H_
#define _FLAT_MATERIAL_H_

#include "material.h"


class FlatMaterial : public Material {

private:

    Color diffuse; // <! The Material color

public:

    /**
     * @brief Construct a new Flat Material object
     * 
     * @param diffuse  The material Color
     */
    FlatMaterial ( Color diffuse )
    : diffuse{diffuse} {}

    

};

#endif