#ifndef _BLINN_PHONG_MATERIAL_
#define _BLINN_PHONG_MATERIAL_

/**
 * @file blinnPhongMaterial.h
 * @author your Gabriel Araújo de Souza (gabriel_feg@hotmail.com)
 * @brief  A new material for raytracer
 * @version 0.1
 * @date 2019-05-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "material.h"
#include "../common.h"

/**
 * @brief A new material that implements the
 * Blinn-Phong Reflection Model
 */
class BlinnPhongMaterial : public Material 
{ 

private:
    const FloatColor ka;  //<! Ambient Coefficient 
    const FloatColor kd;  //<! Diffuse Coefficient
    const FloatColor ks;  //<! Specular Coefficient
    const int ge;   //<! Glossiness Expoent

public:


    /**
     * @brief Construct a new Blinn Phong Material object
     * 
     * @param name   The material name 
     * @param ka     the ambient coefficient
     * @param kd     the diffuse coefficient
     * @param ks     the specular coefficient
     * @param ge     the glossiness expoent 
     */
    BlinnPhongMaterial ( 
        std::string name,
        FloatColor ka, 
        FloatColor kd,
        FloatColor ks,
        int ge
    ) : Material {name},
        ka{ka}, kd{kd}, ks{ks}, ge{ge} {}

    /**
     * @brief Destroy the Blinn Phong Material object
     */
    ~BlinnPhongMaterial(){ /*empty*/ }

    /**
     * @brief get a ambient coefficient
     * @return FloatColor  the ambient coefficient (ka)
     */
    FloatColor ka (){ return this->ka; }

    /**
     * @brief get a diffuse coefficient
     * @return FloatColor  the diffuse coefficiente (kd)
     */
    FloatColor kd (){ return this->kd; }

    /**
     * @brief get a specular coefficient
     * @return FloatColor  the specular coefficient (ks)
     */
    FloatColor ks (){ return this->ks; }

    /**
     * @brief get a glossiness coefficient
     * @return float the glossiness coefficient (ge)
     */
    int ge (){ return this->ge; }

};

#endif