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
    const point3 ka;  //<! Ambient Coefficient 
    const point3 kd;  //<! Diffuse Coefficient
    const point3 ks;  //<! Specular Coefficient
    const float ge;   //<! Glossiness Expoent

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
        point3 ka, 
        point3 kd,
        point3 ks,
        float ge
    ) : Material {name},
        ka{ka}, kd{kd}, ks{ks}, ge{ge} {}

    /**
     * @brief Destroy the Blinn Phong Material object
     */
    ~BlinnPhongMaterial(){ /*empty*/ }

    /**
     * @brief get a ambient coefficient
     * @return point3  the ambient coefficient (ka)
     */
    point3 ka (){ return this->ka; }

    /**
     * @brief get a diffuse coefficient
     * @return point3  the diffuse coefficiente (kd)
     */
    point3 kd (){ return this->kd; }

    /**
     * @brief get a specular coefficient
     * @return point3  the specular coefficient (ks)
     */
    point3 ks (){ return this->ks; }

    /**
     * @brief get a glossiness coefficient
     * @return float the glossiness coefficient (ge)
     */
    float ge (){ return this->ge; }

};

#endif