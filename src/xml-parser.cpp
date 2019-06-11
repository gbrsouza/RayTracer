/**
 * @file xml-parser.cpp
 * @author Gabriel Araújo de Souza (gabriel_feg@hotmail.com)
 * @brief  The parser to xml files
 * @version 0.1
 * @date 2019-05-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "xml-parser.h"

/*
 +=====================================+
 |         Readers like tools          |
 +=====================================+
*/

/**
 * @brief  read a string like a attribute of object
 * in the file
 * 
 * @param e           the pointer to file
 * @param identifier  the identifier of attribute
 * @return std::string  the string in the identifier
 */
std::string 
read_a_string (
    XMLElement &e,
    std::string identifier )
{
    const char * string = nullptr;
    string = e.Attribute(identifier.c_str());
    if (string == nullptr) throw XML_ERROR_PARSING_ATTRIBUTE;
    std::string result = string;

    return result;
} 

/**
 * @brief Read float value in the document
 * 
 * @param element   the pointer to file
 * @param value     the string value of float element
 * @return float    the float value
 */
float
read_float(
    XMLElement &element,
    std::string value)
{
    float x;
    XMLError eResult;

    eResult = element.QueryFloatAttribute(value.c_str(), &x);
    if (eResult != XML_SUCCESS) throw XML_ERROR_PARSING_ATTRIBUTE;
    return x;
}

/**
 * @brief read a vector or point3 
 * 
 * @param element the iterator of file
 * @return Vec3*  the vector or point3
 */
Vec3* 
read_vector_or_point(
    XMLElement &element)
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

Vec3* 
read_float_vector(
    XMLElement &element)
{
    float x, y, z;
    XMLError eResult;

    eResult = element.QueryFloatAttribute("x", &x);
    if (eResult != XML_SUCCESS) throw INVALID_ATT_VECTOR_OR_POINT;
    eResult = element.QueryFloatAttribute("y", &y);
    if (eResult != XML_SUCCESS) throw INVALID_ATT_VECTOR_OR_POINT;
    eResult = element.QueryFloatAttribute("z", &z);
    if (eResult != XML_SUCCESS) throw INVALID_ATT_VECTOR_OR_POINT;
    Vec3 *pos = new Vec3(x,y,z);

    return pos;
}

/**
 * @brief Read a RGB color by a pointer
 * 
 * @param e    the iterator 
 * @return Color*  the color 
 */
Color24 *
read_a_color (
    XMLElement &e)
{
    int r, g, b;
    XMLError eResult;

    eResult = e.QueryIntAttribute("r", &r);
    if (eResult != XML_SUCCESS) throw XML_ERROR_PARSING_ATTRIBUTE;
    eResult = e.QueryIntAttribute("g", &g);
    if (eResult != XML_SUCCESS) throw XML_ERROR_PARSING_ATTRIBUTE;
    eResult = e.QueryIntAttribute("b", &b);
    if (eResult != XML_SUCCESS) throw XML_ERROR_PARSING_ATTRIBUTE;

    Color24 *color = new Color24(r, g, b);
    return color;
}

point3 *
read_a_float_color (
    XMLElement &e)
{
    float r, g, b;
    XMLError eResult;

    eResult = e.QueryFloatAttribute("r", &r);
    if (eResult != XML_SUCCESS) throw XML_ERROR_PARSING_ATTRIBUTE;
    eResult = e.QueryFloatAttribute("g", &g);
    if (eResult != XML_SUCCESS) throw XML_ERROR_PARSING_ATTRIBUTE;
    eResult = e.QueryFloatAttribute("b", &b);
    if (eResult != XML_SUCCESS) throw XML_ERROR_PARSING_ATTRIBUTE;

    point3 *color = new point3(r, g, b);
    return color;
}

/*
 +=====================================+
 |  Readers of specifics shapes type   |
 +=====================================+
 */

/**
 * @brief read a sphere
 * 
 * @param element   the pointer to file 
 * @return std::shared_ptr<Shape>  The pointer
 * to Sphere
 */
std::shared_ptr<Shape> 
read_sphere(
    XMLElement &e,
    Material * m)
{
    XMLElement * p = e.FirstChildElement("radius");
    if (p == nullptr) throw INVALID_SPHERE;

    float radius;
    XMLError eResult;
    
    // Get value of radius
    eResult = p->QueryFloatAttribute("value", &radius);
    if (eResult != XML_SUCCESS) throw XML_ERROR_PARSING_ATTRIBUTE;

    // Get center of sphere
    float x, y, z;
    p = e.FirstChildElement("center");
    
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
    const point3 *center = new point3(x,y,z);
    Shape *sphere = new Sphere(*center, radius, m);
    std::shared_ptr<Shape> ptr(sphere);

    return ptr;
}


/*
 +=====================================+
 | Readers of specifics materials type |
 +=====================================+
 */

/**
 * @brief read a flat material
 * 
 * @param e    the pointer to file
 * @param name the name of material
 * @return std::shared_ptr<FlatMaterial> the pointer
 * to flat material.  
 */
std::shared_ptr<Material> 
read_flat_material ( 
    XMLElement &e,
    std::string name )
{
    XMLElement * diffuse = e.FirstChildElement("diffuse");
    if (diffuse == nullptr) throw INVALID_MATERIAL;

    XMLError eResult;
    int r, g, b;

    // Get value of red
    eResult = diffuse->QueryIntAttribute("r", &r);
    if (eResult != XML_SUCCESS) throw INVALID_COLOR;

    // Get value of green
    eResult = diffuse->QueryIntAttribute("g", &g);
    if (eResult != XML_SUCCESS) throw INVALID_COLOR;

    // Get value of blue
    eResult = diffuse->QueryIntAttribute("b", &b);
    if (eResult != XML_SUCCESS) throw INVALID_COLOR;

    Color * c = new Color( r, g, b );
    Material * m = new FlatMaterial( *c, name );
    std::shared_ptr<Material> fm(m);

    return fm;
}

std::shared_ptr<Material>
read_blinn_material (
    XMLElement &e,
    std::string name)
{
    XMLElement * amb = e.FirstChildElement("ambient");
    if (amb == nullptr) throw INVALID_MATERIAL;

    std::shared_ptr<Color> cAmb(read_a_float_color(*amb));

    XMLElement * dif = e.FirstChildElement("diffuse");
    if (dif == nullptr) throw INVALID_MATERIAL;

    std::shared_ptr<Color> cDif(read_a_float_color(*dif));

    XMLElement * spe = e.FirstChildElement("specular");
    if (spe == nullptr) throw INVALID_MATERIAL;

    std::shared_ptr<Color> cSpe(read_a_float_color(*spe));

    XMLElement * glo = e.FirstChildElement("glossiness");
    if (glo == nullptr) throw INVALID_MATERIAL;

    XMLError eResult;
    int glossiness;
    eResult = glo->QueryIntAttribute("value", &glossiness);
    if (eResult != XML_SUCCESS) throw INVALID_MATERIAL;

    std::shared_ptr<Material> m(
        new BlinnMaterial(name, *cAmb.get(), *cDif.get(), 
                          *cSpe.get(), glossiness));

    return m;

}

/*
 +=====================================+
 |  Readers of specifics camera type   |
 +=====================================+
 */

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
OrthographicCamera* 
read_orthographic_camera(
    XMLElement &element,
    std::shared_ptr<Film> film, 
    point3 &pos,
    point3 &target,
    vector &vUp)
{
    float l, r, b, t;

    XMLElement *vpdim = element.FirstChildElement("vpdim");
    if ( vpdim == nullptr) throw INVALID_ORT_CAMERA;
    l = read_float(*vpdim, "l");
    r = read_float(*vpdim, "r");
    b = read_float(*vpdim, "b");
    t = read_float(*vpdim, "t");

    OrthographicCamera *ortCam = new OrthographicCamera(film, 
        pos, target, vUp, l,r,b,t);
    return ortCam;
}

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
PespectiveCamera* 
read_pespective_camera (
    XMLElement &element, 
    std::shared_ptr<Film> film, 
    point3 &pos,
    point3 &target, 
    vector &vUp)
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

    PespectiveCamera *pespcCam = new PespectiveCamera(film, 
        pos, target, vUp, fovy, aspect, fdistance);
    return pespcCam;
}

/*
 +==========================================+
 |  Readers of specifics integrators type   |
 +==========================================+
 */
DepthIntegrator *
read_depth_integrator(
    XMLElement &e,
    Camera * camera,
     std::shared_ptr<Sampler> sampler )
{
    XMLElement *i = e.FirstChildElement("near_color");
    if (i == nullptr) throw INVALID_SCENE;
    Color24 *near = read_a_color( *i );
        
    i = e.FirstChildElement("far_color");
    if (i == nullptr) throw INVALID_SCENE;
    Color24 *far = read_a_color( *i );

    DepthIntegrator *integrator = new DepthIntegrator( 
            std::shared_ptr<Camera>(camera),
            sampler, *near, *far);

    return integrator;
}

/*
 +=====================================+
 |  Readers of specifics lights type   |
 +=====================================+
 */

std::shared_ptr<AmbientLight>
read_ambient_light(
    XMLElement &e)
{
    XMLElement *i = e.FirstChildElement("intensity");
    if (i == nullptr) throw INVALID_SCENE;
    point3 *intensity = read_a_float_color( *i );

    std::shared_ptr<AmbientLight> m (new AmbientLight(*intensity) );
    return m;
}

std::shared_ptr<PointLight>
read_point_light(
    XMLElement &e)
{
    XMLElement *i = e.FirstChildElement("intensity");
    if (i == nullptr) throw INVALID_SCENE;
    point3 *intensity = read_a_float_color( *i );

    XMLElement *p = e.FirstChildElement("position");
    if (p == nullptr) throw INVALID_SCENE;
    point3 *position = read_float_vector( *p );

    std::shared_ptr<PointLight> m ( new PointLight(*intensity, *position) );
    return m;
}

std::shared_ptr<DirectionalLight>
read_directional_light(
    XMLElement &e)
{
    XMLElement *i = e.FirstChildElement("intensity");
    if (i == nullptr) throw INVALID_SCENE;
    point3 *intensity = read_a_float_color( *i );

    i = e.FirstChildElement("direction");
    if (i == nullptr) throw INVALID_SCENE;
    point3 *direction = read_float_vector( *i );

    std::shared_ptr<DirectionalLight> m ( new DirectionalLight(*intensity, *direction) );
    return m;
}

std::shared_ptr<SpotyLight>
read_spoty_light(
    XMLElement &e)
{
    XMLError eResult;

    XMLElement *i = e.FirstChildElement("intensity");
    if ( i == nullptr ) throw INVALID_SCENE;
    point3 *intensity = read_a_float_color( *i );

    i = e.FirstChildElement("position");
    if ( i == nullptr ) throw INVALID_SCENE;
    point3 *position = read_vector_or_point( *i );

    i = e.FirstChildElement("point_at");
    if ( i == nullptr ) throw INVALID_SCENE;
    point3 *point_at = read_vector_or_point( *i );

    int cutoff, falloff;
    i = e.FirstChildElement("cutoff");
    eResult = i->QueryIntAttribute("value", &cutoff);
    if (eResult != XML_SUCCESS) throw INVALID_SCENE;

    i = e.FirstChildElement("falloff");
    eResult = i->QueryIntAttribute("value", &falloff);
    if (eResult != XML_SUCCESS) throw INVALID_SCENE;
    
    std::shared_ptr<SpotyLight> spoty ( 
        new SpotyLight(*intensity, *position, *point_at, cutoff, falloff));
    
    return spoty;

}

/*
 +=====================================+
 |   implements readers of interface   |
 +=====================================+
 */

void 
ParserXML::read_background(
    XMLNode &pRoot)
{
    
    // Get backgroung tag
    XMLElement * pElement = pRoot.FirstChildElement("background");
    if (pElement == nullptr) throw XML_ERROR_PARSING_ELEMENT;

    // Get type of background
    std::string background_type = read_a_string(*pElement, "type");

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

Color* 
ParserXML::read_color(
    int number_colors,
    XMLElement &element)
{
    
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

void 
ParserXML::read_camera(
    XMLNode &pRoot)
{

    int w, h;
    XMLError eResult;

    XMLElement * pElement = pRoot.FirstChildElement("camera");
    if (pElement == nullptr) throw INVALID_CAMERA;

    //Get type of camera
    std::string type = read_a_string(*pElement, "type");

    /*
     +==================================+
     | Read the retina/image dimensions |
     +==================================+
    */

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

    //Get settings of camera
    XMLElement * settings = pElement->FirstChildElement("img_file");
    if (settings == nullptr) throw INVALID_CAMERA;
    
    // Get name of output
    if (settings->Attribute("name") != nullptr)
        this->output = pElement->Attribute("name");
    else this->output = "output";

    // Get image extension
    if (settings->Attribute("type") != nullptr)
        this->extension = pElement->Attribute("type");
    else this->extension = "PPM";

    std::shared_ptr<Film> film( new Film(w, h, output, extension) );

    /*
     +=======================+
     | Read the camera frame |
     +=======================+
     */

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

    /*
     +==============================+
     | Read the specific parameters |
     +==============================+
    */

    // Generate Camera
    if (type.compare("orthographic")==0){
        this->camera = read_orthographic_camera(*pElement, film, *pos, *tgt, *vUp );
    }else if (type.compare("perspective")==0){
        this->camera = read_pespective_camera(*pElement, film, *pos, *tgt, *vUp );
    }else throw INVALID_CAMERA;

    this->buffer = new Buffer(w,h);
} 

void 
ParserXML::read_scene(
    XMLNode &pRoot)
{
    XMLElement * pElement = pRoot.FirstChildElement("scene");
    if (pElement == nullptr) throw INVALID_SCENE;

    // Read the background   
    this->read_background(*pElement); 
    // Read all materials
    XMLElement * pListMaterials = pElement->FirstChildElement("material");
    int count = 0;
    while ( pListMaterials != nullptr )
    {
        count++;

        //Get type of material
        std::string type = read_a_string(*pListMaterials, "type");

        //Get name of material
        std::string name = read_a_string(*pListMaterials, "name");
        //Get specific parameters
        std::shared_ptr<Material> m;
        if (type.compare("flat") == 0)
            m = read_flat_material(*pListMaterials, name);    
        else if (type.compare("blinn") == 0 )
            m = read_blinn_material(*pListMaterials, name);        

        this->materials.push_back(m);

        pListMaterials = pListMaterials->NextSiblingElement("material");

    }
    std::cout << "      >>> " << count << " materials found\n";

    // read all objects
    XMLElement * pListElement = pElement->FirstChildElement("object");
    count = 0;
    while (pListElement != nullptr){

        // increments id
        count++;
       
        //Get type of object
        std::string type = read_a_string(*pListElement, "type");
    
        //Get material's name of object
        std::string materialName = read_a_string(*pListElement, "material");
        Material * m = get_material(materialName).get();
        //Get the shape
        std::shared_ptr<Shape> shape;
        if (type.compare("sphere") == 0)
            shape = read_sphere(*pListElement, m);
        // add here new shapes

        //Set shape's id
        shape->set_id( count );

        //Create a new primitive
        Primitive *p = new GeometricPrimitive( shape, get_material(materialName) );
        
        std::shared_ptr<Primitive> primitive(p);
        this->primitives.push_back(primitive);

        //Next element
        pListElement = pListElement->NextSiblingElement("object");

    }
    std::cout << "      >>> " << count << " objects found\n";

    //read all ligths
    count =0;
    XMLElement * pListLights = pElement->FirstChildElement("light");
    while (pListLights != nullptr){
        std::string type = read_a_string( *pListLights, "type" );
        if ( type.compare("ambient") == 0 )
            this->lights.push_back( read_ambient_light(*pListLights) );
        else if ( type.compare("point") == 0 )
            this->lights.push_back( read_point_light(*pListLights) );
        else if (type.compare("spot") == 0)
            this->lights.push_back( read_spoty_light(*pListLights) );
        else if (type.compare("directional") == 0)
            this->lights.push_back( read_directional_light(*pListLights) );

        count++;
        pListLights = pListLights->NextSiblingElement("light");
    }

    std::cout << "      >>> " << count << " lights found\n";
}

void 
ParserXML::read_integrator( 
    XMLNode &pRoot )
{
    XMLElement * pElement = pRoot.FirstChildElement("running");
    if (pElement == nullptr) throw INVALID_SCENE;

    pElement = pElement->FirstChildElement("integrator");
    if (pElement == nullptr) throw INVALID_SCENE;

    std::string type = read_a_string( *pElement, "type" );
    integratorType = type;

    std::shared_ptr<Sampler> sampler(new Sampler());
    if ( type.compare("flat") == 0 )      
        integrator = new FlatIntegrator(std::shared_ptr<Camera>(camera), sampler);
    else if ( type.compare("depth map") == 0)        
        integrator = read_depth_integrator(*pElement, this->camera, sampler );
    else if ( type.compare("normal map") == 0 )    
        integrator = new NormalMapIntegrator(std::shared_ptr<Camera>(camera), sampler);
    else if ( type.compare("blinn_phong") == 0)
        integrator = new BlinnPhongIntegrator(std::shared_ptr<Camera>(camera), sampler); 


    //@TODO get a sampler

}


void 
ParserXML::run()
{
    XMLDocument doc;

    XMLError eResult = doc.LoadFile( filename.c_str() );
    if (eResult != XML_SUCCESS) throw INVALID_XML;

    XMLNode *pRoot = doc.FirstChild();
    if (pRoot == nullptr) throw XML_ERROR_FILE_READ_ERROR;

    std::cout << "\n>>> reading camera... \n";
    read_camera(*pRoot);
    std::cout << ">>> camera done! \n";
 
    std::cout << "\n>>> reading scene... \n";
    read_scene(*pRoot);
    std::cout << ">>> scene done! \n"; 

    std::cout << "\n>>> reading integrator... \n";
    read_integrator(*pRoot);
    std::cout << ">>> integrator done! \n"; 
    

}   