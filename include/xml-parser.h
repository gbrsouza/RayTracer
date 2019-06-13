#ifndef _XML_PARSERXML_H_
#define _XML_PARSERXML_H_



#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>

#include "background.h"
#include "tinyxml2.h"
#include "vec3.h"
#include "canvas.h"
#include "cameras/orthographic_camera.h"
#include "cameras/pespective_camera.h"
#include "primitives/geometricPrimitive.h"
#include "shapes/sphere.h"
#include "materials/flatMaterial.h"

#include "integrators/depthIntegrator.h"
#include "integrators/flatIntegrator.h"
#include "integrators/normalMapIntegrator.h"
#include "integrators/blinnPhongIntegrator.h"

#include "lights/ambientLight.h"
#include "lights/pointLight.h"
#include "lights/spotyLight.h"
#include "lights/directionalLight.h"

#define INVALID_XML                 "Invalid XML specification"
#define INVALID_SETTINGS            "Invalid settings specification"
#define INVALID_BACKGROUND          "Invalid background specification"
#define INVALID_COLOR               "Invalid color specification"
#define INVALID_CAMERA              "Invalid Camera specification"
#define INVALID_ORT_CAMERA          "Invalid Orthographic Camera specification"
#define INVALID_PESPC_CAMERA        "Invalid Pespective Camera specification"
#define INVALID_ATT_VECTOR_OR_POINT "Invalid attribute defined for vector or point"
#define INVALID_SCENE               "Invalid scene specification"
#define INVALID_SPHERE              "Invalid sphere specification"
#define INVALID_TRIANGLE            "Invalid triangle specification"
#define INVALID_MATERIAL            "Invalid Material specification"

using namespace tinyxml2;

class ParserXML {

private:  

    /**
     * @brief Read a background in xml file
     * 
     * @param element  the iterator of file
     * @return Background&   The object background defined
     */
    void read_background(XMLNode &pRoot);

    /**
     * @brief Read a set of colors in xml file
     * 
     * @param number_colors the number of colors for read
     * @param element  the iterator of file
     * @return Color*  the readed array of colors
     */
    Color* read_color(int number_colors, XMLElement &element);
   
    /**
     * @brief Read a buffer of xml file
     * 
     * @param element  the iterator of file
     */
    void read_camera(XMLNode &pRoot); 

    /**
     * @brief Read a scene
     *  
     * @param pRoot The iterator of file
     */
    void read_scene(XMLNode &pRoot);

    /**
     * @brief Read the type of integrator
     * 
     * @param pRoot The iterator of file
     */
    void read_integrator(XMLNode &pRoot);


public:

    std::string filename;   //<! The xml file with the description raytracer
    std::string output;     //<! The name of output image
    std::string extension;  //<! The image extension
    std::string integratorType; //<
    
    Background *background; //<! The background
    Buffer *buffer;         //<! The buffer
    Camera *camera;         //<! The Camera
    Integrator *integrator;

    //<! list of objects in the scene. Not yet implemented.
    std::vector<std::shared_ptr<Primitive>> primitives;

    //<! list of materials in the scene.
    std::vector<std::shared_ptr<Material>> materials;

    //<! lis of lights in the scene
    std::vector<std::shared_ptr<Light>> lights;
    
    /**
     * @brief Construct a new ParserXML object
     * @param filename the name of xml file
     */
    ParserXML (std::string filename)
    { this->filename = filename; }

    /**
     * @brief Destroy the ParserXML object
     */
    ~ParserXML()
    { }

    /**
     * @brief run the algorithm
     */
    void run();

    /**
     * @brief Get the material object
     * 
     * @param nameOfMaterial  The name of material
     * @return std::shared_ptr<Material>  the material
     * that was found
     */
    std::shared_ptr<Material> 
    get_material( 
        std::string nameOfMaterial )
    {
        for ( const auto m : materials ){
            if (m->get_name().compare(nameOfMaterial) == 0)
                return m;
        }

        return nullptr;
    }
};

#endif