#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "../common.h"

class Material{

public:

    /**
     * @brief Construct a new Material object
     * 
     * @param name The material's name
     */
    Material ( std::string name )
    : name{name} {}

    /**
     * @brief Construct a new Material object
     */
    Material () {}

    /**
     * @brief Destroy the Material object
     */
    virtual ~Material(){ /*empty*/ }

    /**
     * @brief Get the name object
     * @return std::string  the material's name
     */
    std::string get_name ()
    { return name; }

private:

    std::string name; //<! The material's name

};

#endif