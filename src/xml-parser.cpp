#include "xml-parser.h"

void ParserXML::read_settings(XMLNode &pRoot){

    // Get output defination
    XMLElement * pElement = pRoot.FirstChildElement("settings")->FirstChildElement("output_file");
    if (pElement == nullptr) throw XML_ERROR_PARSING_ELEMENT;

    // Get name of output
    if (pElement->Attribute("name") != nullptr)
        this->output = pElement->Attribute("name");
    else this->output = "output";
}

void ParserXML::read_background(XMLNode &pRoot){
    
    // Get backgroung tag
    XMLElement * pElement = pRoot.FirstChildElement("background");
    if (pElement == nullptr) throw XML_ERROR_PARSING_ELEMENT;
    
    // Get type of background
    const char * attribute_text = nullptr;
    attribute_text = pElement->Attribute("type");
    if (attribute_text == nullptr) throw XML_ERROR_PARSING_ATTRIBUTE;
    std::string background_type = attribute_text;

    // Get colors and construct background
    if (background_type.compare("interpolation")==0){
   
        // read four colors
        Color *colors = read_color(4, *pElement);
        this->background = new Background(colors[0], colors[1], colors[2], colors[3]);
   
    } else if (background_type.compare("solid")==0){
        
        // read one color
        Color *colors = read_color(1, *pElement);
        this->background = new Background(colors[0]);
   
    }else if (background_type.compare("gradient")==0){
        
        // read two colors
        Color *colors = read_color(2, *pElement);
        this->background = new Background(colors[0], colors[1]);
    
    }else throw INVALID_BACKGROUND;
}
Color* ParserXML::read_color(int number_colors, XMLElement &element){
    
    // Definations
    int count = 0, red=0, green=0, blue=0;
    Color *colors = new Color[number_colors];
    XMLError eResult;
 
    // Get first element of color list
    XMLElement * pListElement = element.FirstChildElement("color");
    
    // Get all defined colors
    while ( pListElement != nullptr ){

        // Get value of red
        eResult = pListElement->QueryIntAttribute("r", &red);
        if (eResult != XML_SUCCESS) throw INVALID_COLOR;

        // Get value of green
        eResult = pListElement->QueryIntAttribute("g", &green);
        if (eResult != XML_SUCCESS) throw INVALID_COLOR;

        // Get value of blue
        eResult = pListElement->QueryIntAttribute("b", &blue);
        if (eResult != XML_SUCCESS) throw INVALID_COLOR;
          
        colors[count] = Color(red, green, blue);        
       
        count++;
        pListElement = pListElement->NextSiblingElement("color");
    }

    // check if number of read colors is equals to the informed
    if (count != number_colors) throw INVALID_BACKGROUND;
    else return colors;
}

void ParserXML::read_camera(XMLNode &pRoot){

    int w, h;
    XMLError eResult;

    XMLElement * pElement = pRoot.FirstChildElement("camera");
    if (pElement == nullptr) throw INVALID_CAMERA;

    // Get width of camera
    XMLElement * width = pElement->FirstChildElement("width");
    if (width == nullptr) throw INVALID_CAMERA;
    eResult = width->QueryIntAttribute("value", &w);
    if (eResult != XML_SUCCESS) throw INVALID_CAMERA;
   
    //Get height of camera
    XMLElement * height = pElement->FirstChildElement("height");
    if (height == nullptr) throw INVALID_CAMERA;
    eResult = height->QueryIntAttribute("value", &h);
    if (eResult != XML_SUCCESS) throw INVALID_CAMERA;

    this->buffer = new Buffer(w,h);
} 

OrthographicCamera 
ParserXML::read_orthographic_camera(
    XMLElement &element, int width, int height)
{
    int x, y, z;
    float l, r, b, t;
    XMLError eResult;

    XMLElement *position = element.FirstChildElement("position");
    if (position = nullptr) throw INVALID_ORT_CAMERA;
    point3 pos = read_vector_or_point(*position);
    
    XMLElement *target = element.FirstChildElement("target");
    if (target = nullptr) throw INVALID_ORT_CAMERA;
    point3 tgt = read_vector_or_point(*target);

    XMLElement *up = element.FirstChildElement("up");
    if ( up = nullptr) throw INVALID_ORT_CAMERA;
    point3 vUp = read_vector_or_point(*up);
  
    XMLElement *vpdim = element.FirstChildElement("vpdim");
    if ( vpdim = nullptr) throw INVALID_ORT_CAMERA;
    l = read_float(*vpdim, "l");
    r = read_float(*vpdim, "r");
    b = read_float(*vpdim, "b");
    t = read_float(*vpdim, "t");

    OrthographicCamera ortCam = OrthographicCamera(width,height, pos, tgt, vUp, l,r,b,t);
}

Vec3 ParserXML::read_vector_or_point(XMLElement &element)
{
    int x, y, z;
    XMLError eResult;

    eResult = element.QueryIntAttribute("x", &x);
    if (eResult != XML_SUCCESS) throw INVALID_ATT_VECTOR_OR_POINT;
    eResult = element.QueryIntAttribute("y", &y);
    if (eResult != XML_SUCCESS) throw INVALID_ATT_VECTOR_OR_POINT;
    eResult = element.QueryIntAttribute("z", &z);
    if (eResult != XML_SUCCESS) throw INVALID_ATT_VECTOR_OR_POINT;
    Vec3 pos = Vec3(x,y,z);

    return pos;
}

float read_float(XMLElement &element, std::string value)
 {
    float x;
    XMLError eResult;

    eResult = element.QueryFloatAttribute(value.c_str(), &x);
    if (eResult != XML_SUCCESS) throw XML_ERROR_PARSING_ATTRIBUTE;
    return x;
 }

#include <iostream>
void ParserXML::run(){
    
    XMLDocument doc;

    XMLError eResult = doc.LoadFile( filename.c_str() );
    if (eResult != XML_SUCCESS) throw INVALID_XML;

    XMLNode *pRoot = doc.FirstChild();
    if (pRoot == nullptr) throw XML_ERROR_FILE_READ_ERROR;

    read_settings(*pRoot);
    read_background(*pRoot);
    read_camera(*pRoot);
}   