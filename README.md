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
Initially, it is necessary introduce a ray tracer through of tag `<raytracer></raytracer>` . In your xml file, You must define four basic sections: settings, background ,camera and scene, for this, use the tags `<settings></settings>` , `<background></background>`, `<camera><camera>` and `<scene></scene>` respectively. In settings, you define the image format and image name. For background, you define the background type renderization and all colors. For camera, you define the width and height size of image and for scene, you define all objects of image. A basic document is shown below.

```xml
<raytracer>
	<settings>
    		<output_file type="PNG" name="saida"></output_file>
 	</settings>

	<background type="interpolation">
   		<color r="0"   g="0"   b="51"/>  <!-- bottom left  -->
   		<color r="0"   g="255" b="51"/>  <!-- top left     -->
   		<color r="255" g="255" b="51"/>  <!-- top right    -->
   		<color r="255" g="0"   b="51"/>  <!-- bottom right -->
 	</background>

	<camera>
		<width value="200"></width>
		<height value="100"></height>
	</camera>
	
	<scene>
		...
	</scene>

</raytracer>
```

### Settings

In this tag you add a another tag named `output_file`. For this new tag you add tow attributes

* Optional attibutes
	- `name`  : The image's name (default: output)
	- `type`  : The image extension (default: PPM)
	
#### Example
```xml
<settings>
    	<output_file type="PNG" name="saida"></output_file>
</settings>
```

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

### Camera

In the camera, you need to set the width and height of image. For this, use the tags `<width></width>` and `<height></height>`.
The required attributes in tags are `value`. For a generic camera, three values are necessary: `<position></position>` to represent the camera position, `<target></target>` to looking down the -Z axis and `<up></up>` that is the camera's up vector.

#### Example
```xml
<camera type="...">
	<!--- The camera frame -->
    	<position x="0" y="0" z="0"/> <!--- located at the origin -->
    	<target x="0" y="0" z="-10"/> <!--- looking down the -Z axis -->
    	<up x="0" y="1" z="1"/>       <!--- the camera's up vector -->
	<width value="200"></width>
	<height value="100"></height>
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
## Objects
For specify an object in scene, the tag `<object></object>` must used. It is necessary to inform the type of object. The allowed types are informed below.

#### Sphere

* Required attibutes 
	- `radius` - The radius size of sphere (use the tag `<radius>`)
	- `center` - The 3D point for sphere center (use the tag `<center>` ) 
		
##### Example
```xml
<scene>
	<object type="sphere" name="sphere1">
            <radius value="0.4"/>
            <center x="-1.0" y="0.5" z="-5"/>
        </object>
        <object type="sphere" name="sphere2">
            <radius value="0.4"/>
            <center x="1.0" y="-0.5" z="-8"/>
        </object>
        <object type="sphere" name="sphere3">
            <radius value="0.4"/>
            <center x="-1.0" y="-1.5" z="-3.5"/>
        </object>
</scene>	
```


###### © 2019 Souza, Gabriel A. Powered by [TinyXML-2](https://github.com/leethomason/tinyxml2)
