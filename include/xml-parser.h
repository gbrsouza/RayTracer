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
     * @brief read the atributes of a orthographic camera
     * 
     * @param element the iterator of file
     * @param width   the width of camera
     * @param height  the height of camera
     * @param pos     the position of camera
     * @param target  the target of camera
     * @param vUp     the uo vector
     * @return OrthographicCamera* the orthographic camera
     */
    OrthographicCamera* read_orthographic_camera(
        XMLElement &element,int width, int height,
        point3 &pos, point3 &target, vector &vUp);

    /**
     * @brief read the atributes of a pespective camera
     * 
     * @param element the iterator of file
     * @param width   the width of camera
     * @param height  the height of camera
     * @param pos     the position of camera
     * @param target  the target of camera
     * @param vUp     the uo vector
     * @return PespectiveCamera* the pespective camera
     */    
    PespectiveCamera* read_pespective_camera (
       XMLElement &element,int width, int height,
       point3 &pos, point3 &target, vector &vUp);

    /**
     * @brief read a vector or point3 
     * 
     * @param element the iterator of file
     * @return Vec3*  the vector or point3
     */
    Vec3* read_vector_or_point(XMLElement &element);

    /**
     * @brief Read float value in the document
     * 
     * @param element   the iterator of file
     * @param value     the string value of float element
     * @return float    the float value
     */
    float read_float(XMLElement &element, std::string value);

    /**
     * @brief Read a scene
     *  
     * @param pRoot The iterator of file
     */
    void read_scene(XMLNode &pRoot);


public:

    std::string filename;   //<! The xml file with the description raytracer
    std::string output;     //<! The name of output image
    std::string extension;  //<! The image extension
    Background *background; //<! The background
    Buffer *buffer;         //<! The buffer
    Camera *camera;         //<! The Camera
    

    //<! list of objects in the scene. Not yet implemented.
    std::vector<std::shared_ptr<Primitive>> primitives;

    //<! list of materials in the scene.
    std::vector<std::shared_ptr<Material>> materials;
    
    /**
     * @brief Construct a new ParserXML object
     * @param filename the name of xml file
     */
    ParserXML (std::string filename)
    { this->filename = filename; }

    /**
     * @brief Destroy the ParserXML object
     */
    ~ParserXML(){}

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