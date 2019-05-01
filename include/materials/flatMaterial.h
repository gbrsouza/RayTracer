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
    FlatMaterial ( Color diffuse, std::string name )
    : Material{name}, diffuse{diffuse} {}

    /**
     * @brief Destroy the Flat Material object
     */
    ~FlatMaterial (){}

    /**
     * @brief Get the color object
     * @return Color the color of material
     */
    Color get_color(){ return diffuse; }

};

#endif