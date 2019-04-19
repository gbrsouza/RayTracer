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

    // get position os camera
    XMLElement *position = pElement->FirstChildElement("position");
    if (position == nullptr) throw INVALID_ORT_CAMERA;
    point3 *pos = read_vector_or_point(*position);
    
    // get target of camera
    XMLElement *target = pElement->FirstChildElement("target");
    if (target == nullptr) throw INVALID_ORT_CAMERA;
    point3 *tgt = read_vector_or_point(*target);

    // get up vector
    XMLElement *up = pElement->FirstChildElement("up");
    if ( up == nullptr) throw INVALID_ORT_CAMERA;
    vector *vUp = read_vector_or_point(*up);

    //Get type of camera
    const char * typeOfCamera = nullptr;
    typeOfCamera = pElement->Attribute("type");
    if (typeOfCamera == nullptr) throw INVALID_CAMERA;
    std::string type = typeOfCamera;

    // Generate Camera
    if (type.compare("orthographic")==0){
        this->camera = read_orthographic_camera(*pElement, w, h, *pos, *tgt, *vUp );
    }else if (type.compare("perspective")==0){
        this->camera = read_pespective_camera(*pElement, w, h, *pos, *tgt, *vUp );
    }else throw INVALID_CAMERA;

    this->buffer = new Buffer(w,h);
} 

OrthographicCamera* 
ParserXML::read_orthographic_camera(
    XMLElement &element, int width, int height, 
    point3 &pos, point3 &target, vector &vUp)
{
    float l, r, b, t;

    XMLElement *vpdim = element.FirstChildElement("vpdim");
    if ( vpdim == nullptr) throw INVALID_ORT_CAMERA;
    l = read_float(*vpdim, "l");
    r = read_float(*vpdim, "r");
    b = read_float(*vpdim, "b");
    t = read_float(*vpdim, "t");

    OrthographicCamera *ortCam = new OrthographicCamera(width,height, 
        pos, target, vUp, l,r,b,t);
    return ortCam;
}

PespectiveCamera* 
ParserXML::read_pespective_camera (
    XMLElement &element, int width, int height, 
    point3 &pos, point3 &target, vector &vUp)
{
    float fovy, aspect, fdistance;
    XMLElement *fv = element.FirstChildElement("fovy");
    if ( fv == nullptr) throw INVALID_PESPC_CAMERA;
    fovy = read_float(*fv, "value");

    XMLElement *asp = element.FirstChildElement("aspect");
    if ( asp == nullptr) throw INVALID_PESPC_CAMERA;
    aspect = read_float(*asp, "value");

    XMLElement *fd = element.FirstChildElement("fdistance");
    if ( fd == nullptr) throw INVALID_PESPC_CAMERA;
    fdistance = read_float(*fd, "value");

    PespectiveCamera *pespcCam = new PespectiveCamera(width, height, 
        pos, target, vUp, fovy, aspect, fdistance);
    return pespcCam;
}

Vec3* ParserXML::read_vector_or_point(XMLElement &element)
{
    int x, y, z;
    XMLError eResult;

    eResult = element.QueryIntAttribute("x", &x);
    if (eResult != XML_SUCCESS) throw INVALID_ATT_VECTOR_OR_POINT;
    eResult = element.QueryIntAttribute("y", &y);
    if (eResult != XML_SUCCESS) throw INVALID_ATT_VECTOR_OR_POINT;
    eResult = element.QueryIntAttribute("z", &z);
    if (eResult != XML_SUCCESS) throw INVALID_ATT_VECTOR_OR_POINT;
    Vec3 *pos = new Vec3(x,y,z);

    return pos;
}

float ParserXML::read_float(XMLElement &element, std::string value)
 {
    float x;
    XMLError eResult;

    eResult = element.QueryFloatAttribute(value.c_str(), &x);
    if (eResult != XML_SUCCESS) throw XML_ERROR_PARSING_ATTRIBUTE;
    return x;
 }

void ParserXML::read_scene(XMLNode &pRoot)
{
    XMLElement * pElement = pRoot.FirstChildElement("scene");
    if (pElement == nullptr) throw INVALID_SCENE;

    XMLElement * pListElement = pElement->FirstChildElement("object");
    int count = 0;
    // read all objects in scene
    while (pListElement != nullptr){

        count++;
       
        //Get type of object
        const char * typeOfObject = nullptr;
        typeOfObject = pListElement->Attribute("type");
        if (typeOfObject == nullptr) throw INVALID_CAMERA;
        std::string type = typeOfObject;
    
        std::shared_ptr<Primitive> object;
        if (type.compare("sphere") == 0)
            object = read_sphere(*pListElement);
        // add here new primitives

        object->set_id(count);
        this->scene.push_back(object);

        pListElement = pListElement->NextSiblingElement("object");
    }

}

std::shared_ptr<Primitive> 
ParserXML::read_sphere(XMLElement &element)
{
    XMLElement * p = element.FirstChildElement("radius");
    if (p == nullptr) throw INVALID_SPHERE;

    float radius;
    XMLError eResult;
    
    // Get value of radius
    eResult = p->QueryFloatAttribute("value", &radius);
    if (eResult != XML_SUCCESS) throw XML_ERROR_PARSING_ATTRIBUTE;

    // Get center of sphere
    float x, y, z;
    p = element.FirstChildElement("center");
    
    // Get x axis
    eResult = p->QueryFloatAttribute("x", &x);
    if (eResult != XML_SUCCESS) throw XML_ERROR_PARSING_ATTRIBUTE;
    // Get y axis
    eResult = p->QueryFloatAttribute("y", &y);
    if (eResult != XML_SUCCESS) throw XML_ERROR_PARSING_ATTRIBUTE;
    // Get z axis
    eResult = p->QueryFloatAttribute("z", &z);
    if (eResult != XML_SUCCESS) throw XML_ERROR_PARSING_ATTRIBUTE;

    // make a sphere
    point3 *center = new point3(x,y,z);
    Primitive *sphere = new Sphere(*center, radius);
    std::shared_ptr<Primitive> ptr(sphere);

    return ptr;
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
    read_scene(*pRoot);

}   