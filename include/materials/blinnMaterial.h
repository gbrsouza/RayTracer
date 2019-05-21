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
class BlinnMaterial : public Material 
{ 

private:
    point3 ka;  //<! Ambient Coefficient 
    point3 kd;  //<! Diffuse Coefficient
    point3 ks;  //<! Specular Coefficient
    int ge;   //<! Glossiness Expoent

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
    BlinnMaterial ( 
        std::string name,
        point3 ka, 
        point3 kd,
        point3 ks,
        int ge
    ) : Material {name},
        ka{ka}, kd{kd}, ks{ks}, ge{ge} {}

    /**
     * @brief Destroy the Blinn Phong Material object
     */
    ~BlinnMaterial(){ /*empty*/ }

    /**
     * @brief get a ambient coefficient
     * @return point3  the ambient coefficient (ka)
     */
    point3 get_ka (){ return this->ka; }

    /**
     * @brief get a diffuse coefficient
     * @return point3  the diffuse coefficiente (kd)
     */
    point3 get_kd (){ return this->kd; }

    /**
     * @brief get a specular coefficient
     * @return point3  the specular coefficient (ks)
     */
    point3 get_ks (){ return this->ks; }

    /**
     * @brief get a glossiness coefficient
     * @return float the glossiness coefficient (ge)
     */
    int get_ge (){ return this->ge; }

};

#endif