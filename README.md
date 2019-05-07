# RayTracer

A Ray tracing is a rendering technique for generating an image by tracing the path of light as pixels in an image plane and simulating the effects of its encounters with virtual objects. The technique is capable of producing a very high degree of visual realism, usually higher than that of typical scanline rendering methods, but at a greater computational cost. This makes ray tracing best suited for applications where taking a relatively long time to render a frame can be tolerated, such as in still images and film and television visual effects, and more poorly suited for real-time applications such as video games where speed is critical. [Reference](https://en.wikipedia.org/wiki/Ray_tracing_(graphics))

In this project was construct a basic ray tracer in C++ language.

## How to compile

~~~~
$ make
~~~~

## How to execute

It to run the program is necessary specify an xml file.

~~~~
$ ./exe.out <xml_file>
~~~~

## How to describe a scene
Initially, it is necessary introduce a ray tracer through of tag `<raytracer></raytracer>` . In your xml file, You must define four basic sections: camera, scene and running, for this, use the tags `<camera></camera>` , `<scene></scene>`, and `<running></running>` respectively. In camera, you define the width and height size of image and all camera's configuration. For scene, you define all objects and components of image. In the running, you define the integrator. A basic document is shown below.

```xml
<raytracer>
	<camera>
  		...
		
		<!--- Retina/image dimensions -->
		<width value="800"/>
		<height value="600"/>
		<img_file name="output" type="PNG" />
 	
	</camera>

	<scene>

        	<background type="interpolation"> <!-- This defines an interpolated background -->
            		<color r="153"  g="204"   b="255"/> <!-- bottom left  -->
            		<color r="18"   g="10"    b="143"/> <!-- top left     -->
            		<color r="18"   g="10"    b="143"/> <!-- top right    -->
            		<color r="153"  g="204"   b="255"/> <!-- bottom right -->
        	</background>

		<object type="sphere" name="sphere1" material="green" >
			<radius value="0.4"/>
			<center x="-1.0" y="0.5" z="-5"/>
		</object>

		<!--- Library of materials -->
		<material type="flat" name="gold">
			<diffuse r="236" g="124" b="17"/>
		</material>
	
		...
    
    </scene>

    <running> <!--- Running setup -->
		<integrator type="flat">
        		<spp value="1"/> 
    		</integrator>
    </running>
	
</raytracer>
```

### Camera

In the camera, you need to set the width and height of image. For this, use the tags `<width></width>` and `<height></height>`. The required attributes in tags are `value`. For specify the name of output file and the extension file, use the tag `<img_file>` with the attributes `name` and `type` respectively. For a generic camera, three values are necessary: `<position></position>` to represent the camera position, `<target></target>` to looking down the -Z axis and `<up></up>` that is the camera's up vector.

#### Example
```xml
<camera type="...">
	<!--- The camera frame -->
    	<position x="0" y="0" z="0"/> <!--- located at the origin -->
    	<target x="0" y="0" z="-10"/> <!--- looking down the -Z axis -->
    	<up x="0" y="1" z="1"/>       <!--- the camera's up vector -->
	
	<width value="200"/>
	<height value="100"/>
	<img_file name="output" type="PNG" />
</camera>
```
For specify a camera one must say its type. There exists two types of cameras: the orthographic camera and pespective camera. The perspective camera shooting rays from a single point to every pixel area into the scene, whereas the orthographic shoots rays from each pixel to a direction (usually) perpendicular to the image plane into the scene. The Figure below shows the two types of projective cameras describes so far (original source: P. Shirley and S. Marschner., "Fundamentals of Computer Graphics", 3rd ed., 2009, A K Peters.).

![alt text](https://github.com/GabrielArSouza/RayTracer/blob/master/imgs/cameras.png) 

### Orthographic Camera
* Required attibutes 
	- `vpdim` - View plane dimensions with values l, r, b and t (left, right, bottom, top).

#### example
```xml
<camera type="orthographic">
    	<!--- The camera frame -->
    	<position x="0" y="0" z="0"/> <!--- located at the origin -->
    	<target x="0" y="0" z="-10"/> <!--- looking down the -Z axis -->
    	<up x="0" y="1" z="1"/>       <!--- the camera's up vector -->
    	
	<!--- Specific parameters for orthographic projection -->
    	<vpdim l="-3" r="3" b="-2.25" t="2.25" /> <!--- View plane dimensions [left right bottom top] -->
    	
	<!--- Retina/image dimensions -->
    	<width value="40"/>
    	<height value="30"/>
</camera>
```
### Pespective Camera
* Required attibutes 
	- `fovy` - The vertical field of view
	- `aspect` - Optional parameter, aspect ration W/H
	- `fdistance` - The focal distance
	
#### example
```xml
<camera type="perspective">
    	<!--- The camera frame -->
    	<position x="0" y="0" z="0"/> <!--- located at the origin -->
    	<target x="0" y="0" z="-10"/> <!--- looking down the -Z axis -->
    	<up x="0" y="1" z="1"/>       <!--- the camera's up vector -->

	<!--- Specific parameters for perspective projection -->
    	<fovy value="45.0" />         <!--- The vertical field of view -->
    	<aspect value="1.33"/>        <!--- Optional parameter, aspect ration W/H -->
    	<fdistance value="1" />       <!--- The focal distance -->
    	
	<!--- Retina/image dimensions -->
    	<width value="40"/>
    	<height value="30"/>
  </camera>
```		
### Scene
For scene is necessary a background, objects and materials. Each object has a material.

### Background

Define a background of image

* Required attibutes
	- `type`  : The type of background. Exists three types of background: interpolation, solid and gradient. The interpolation required four colors (use the tag `<color></color>`), solid required one color and gradient required two colors.

The colors difened in background are assign in the corners of the image. The assignment order is bottom left, top left, top right, bottom right. If you define two colors, the first color will be assign in the bottom left and top left, the second color will be assign in the top right and bottom right. 

#### Examples
```xml
<background type="interpolation">
      	<color r="0"   g="0"   b="51"/>  <!-- bottom left  -->
      	<color r="0"   g="255" b="51"/>  <!-- top left     -->
      	<color r="255" g="255" b="51"/>  <!-- top right    -->
 	<color r="255" g="0"   b="51"/>  <!-- bottom right -->
</background>
```

![alt text](https://github.com/GabrielArSouza/RayTracer/blob/master/imgs/saida.png) 

```xml
<background type="gradient">
 	<color r="255" g="255" b="51"/>
      	<color r="255" g="0"   b="51"/>
</background>
```

![alt text](https://github.com/GabrielArSouza/RayTracer/blob/master/imgs/saida2.png) 

```xml
<background type="solid">
	<color r="255" g="0"   b="51"/> 
</background>
```


![alt text](https://github.com/GabrielArSouza/RayTracer/blob/master/imgs/saida3.png) 

```xml
<background type="interpolation">
	<color r="255" g="255" b="51"/>  
      	<color r="255" g="0"   b="51"/>  
	<color r="255" g="0"   b="51"/>
	<color r="255" g="255" b="51"/>
</background>
```

![alt text](https://github.com/GabrielArSouza/RayTracer/blob/master/imgs/saida4.png) 

### Color

* Required attibutes
	- `r` - The red value of RGB color
	- `g` - The green value of RGB color
	- `b` - The blue value of RGB color

#### Examples
```xml
<color r="0"   g="0"   b="51"/> 
<color r="0"   g="255" b="51"/> 
<color r="255" g="255" b="51"/> 
<color r="255" g="0"   b="51"/>  
```

### Objects
For specify an object in scene, the tag `<object></object>` must used. It is necessary to inform the type of object. The allowed types are informed below.

#### Sphere

* Required attibutes
	- `radius` - The radius size of sphere (use the tag `<radius>`)
	- `center` - The 3D point for sphere center (use the tag `<center>` ) 
		
##### Example
```xml
<scene>
	<object type="sphere" name="sphere1" material="green" >
        	<radius value="0.4"/>
        	<center x="-1.0" y="0.5" z="-5"/>
        </object>
</scene>	
```

### Material
It is a object material. 

#### FlatMaterial
This material has a unique attribute, a difusse color. The keyword to this type is `flat`.

```xml
<material type="flat" name="pink">
	<diffuse r="253" g="153" b="253"/>
</material>

```

### Running
The integrator to use in ray tracer

### Flat Integrator
Each time a ray hits an object, regardless of the objects normal or the presence (or absence) of lights, the color is always the same for the entire object.

```xml
<integrator type="flat">
</integrator> 
```

### Depth Map Integrator
The color associated with a hit is calculated as follow: normalize the depth hit in `[Zmin,Zmax]`  and use this normalized value to linearly interpolate a color between white and black. This approach produces a gray scale image representing the depth map of the scene.

```xml
<integrator type="depth map">
	<far_color r="255" g="255" b="255"/>
	<near_color r="0" g="0" b="0"/> 
</integrator>
```

### Normal Map Integrator
The color of a hit is determined by making the normal at the hit point have length 1, and treating its coordinate values as RGB color, where the value in `[0,1]` is maps to `[0,255]`. This is called the normal map of an image.

```xml 
<integrator type="normal map">
</integrator> 
```

###### © 2019 Souza, Gabriel A. Powered by [TinyXML-2](https://github.com/leethomason/tinyxml2)
