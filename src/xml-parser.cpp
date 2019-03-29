#include "xml-parser.h"

void ParserXML::read_settings(XMLNode *pRoot){
    
    XMLElement * pElement = pRoot->FirstChildElement("settings")->FirstChildElement("output_file");
    if (pElement == nullptr) throw XML_ERROR_PARSING_ELEMENT;

    if (pElement->Attribute("name") != nullptr)
        this->output = pElement->Attribute("name");
    else throw INVALID_SETTINGS;

    std::cout << this->output << "\n";

}

void ParserXML::read_background(XMLElement &element){
    
    std::string type;
    
    if (element.NextSiblingElement("background") != nullptr){
        
        if (element.Attribute("type") != nullptr)
            type = element.Attribute("type");
        else type = "interpolation";

        if (type.compare("interpolation")){
            // read four colors
            Color *colors = read_color(4, element);
            this->background = new Background(colors[0], colors[1], colors[2], colors[3]);
        } else if (type.compare("solid")){
            // read one color
            Color *colors = read_color(1, element);
            this->background = new Background(colors[0]);
        } else if (type.compare("gradient")){
            // read two colors
            Color *colors = read_color(2, element);
            this->background = new Background(colors[0], colors[1]);
        } else throw INVALID_BACKGROUND;

    }else throw INVALID_BACKGROUND;
}
Color* ParserXML::read_color(int number_colors, XMLElement &element){
    int count = 0, r=0, g=0, b=0;
    Color *colors[number_colors];

    while ( element.NextSiblingElement("color") != nullptr ){
        
        if (element.Attribute("r") != nullptr) r = std::stoi(element.Attribute("r"));
        if (element.Attribute("g") != nullptr) g = std::stoi(element.Attribute("g"));
        if (element.Attribute("b") != nullptr) b = std::stoi(element.Attribute("b"));

        colors[count] = new Color(r,g,b);        
        count++;
    }
    if (count != number_colors) throw INVALID_BACKGROUND;
    else return *colors;
}

void ParserXML::read_camera(XMLElement &element){
    
    int w, h;
    if (element.NextSiblingElement("camera") != nullptr){
        if (element.NextSiblingElement("width") != nullptr)
            w = std::stoi(element.Attribute("value"));
        else throw INVALID_CAMERA;
        if (element.NextSiblingElement("height") != nullptr)
            h = std::stoi(element.Attribute("value"));
        else throw INVALID_CAMERA;
    }else throw INVALID_CAMERA; 

    this->buffer = new Buffer(w,h);
} 

#include <iostream>
void ParserXML::run(){
    
    XMLDocument doc;

    std::cout << "vai ler\n";
    std::cout << filename << "\n";
    XMLError eResult = doc.LoadFile( filename.c_str() );
    std::cout << eResult << "\n";

    std::cout << "vai verificar\n";
    if (eResult != XML_SUCCESS) throw INVALID_XML;

    std::cout << "leu\n";

    XMLNode *pRoot = doc.FirstChild();
    if (pRoot == nullptr) throw XML_ERROR_FILE_READ_ERROR;

    std::cout << "vai chamar\n";
    read_settings(pRoot);
    std::cout << "leu os settings\n";
    // read_background(*pRoot);
    // read_camera(*pRoot);
}