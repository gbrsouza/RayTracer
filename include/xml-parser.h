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

#define INVALID_XML        "Invalid XML specification"
#define INVALID_SETTINGS   "Invalid settings specification"
#define INVALID_BACKGROUND "Invalid background specification"
#define INVALID_COLOR      "Invalid color specification"
#define INVALID_CAMERA     "Invalid Camera specification"

using namespace tinyxml2;

class ParserXML {

private:  

    /**
     * @brief Read a tag settings in xml file
     * 
     * @param element   the iterator of file
     * @return std::string  The name of output image
     */
    void read_settings(XMLNode *pRoot);

    /**
     * @brief Read a background in xml file
     * 
     * @param element  the iterator of file
     * @return Background&   The object background defined
     */
    void read_background(XMLElement &element);

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
     * @return Buffer& the buffer 
     */
    void read_camera(XMLElement &element); 


public:

    std::string filename;   //<! The xml file with the description raytracer
    std::string output;     //<! The name of output image
    Background *background;  //<! The background
    Buffer *buffer;          //<! The buffer

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
};

#endif