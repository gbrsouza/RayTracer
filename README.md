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
Initially, it is necessary introduce a ray tracer through of tag `<raytracer></raytracer>` . In your xml file, You must define three basic sections: settings, background and camera, for this, use the tags `<settings></settings>` , `<background></background>` and `<camera><camera>` respectively. In settings, you define the image format and image name. For background, you define the background type renderization and all colors. For camera, you define the width and height size of image. A basic document is shown below.

~~~~
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
</raytracer>
~~~~

### Settings

In this tag you add a another tag named `output_file`. For this new tag you add tow attributes

* Optional attibutes
	- `name`  : The image's name (default: output)
	- `type`  : The image extension (default: PPM)
	
#### Example
~~~~
<settings>
    	<output_file type="PNG" name="saida"></output_file>
</settings>
~~~~

### Background

Define a background of image

* Required attibutes
	- `type`  : The type of background. Exists three types of background: interpolation, solid and gradient. The interpolation required four colors (use the tag `<color></color>`), solid required one color and gradient required two colors.

The colors difened in background are assign in the corners of the image. The assignment order is bottom left, top left, top right, bottom right. If you define two colors, the first color will be assign in the bottom left and top left, the second color will be assign in the top right and bottom right. 

#### Examples
~~~~
<background type="interpolation">
      	<color r="0"   g="0"   b="51"/>  <!-- bottom left  -->
      	<color r="0"   g="255" b="51"/>  <!-- top left     -->
      	<color r="255" g="255" b="51"/>  <!-- top right    -->
 	<color r="255" g="0"   b="51"/>  <!-- bottom right -->
</background>
~~~~

![alt text](https://github.com/GabrielArSouza/RayTracer/blob/master/imgs/saida.png) 

~~~~
<background type="gradient">
 	<color r="255" g="255" b="51"/>
      	<color r="255" g="0"   b="51"/>
</background>
~~~~

![alt text](https://github.com/GabrielArSouza/RayTracer/blob/master/imgs/saida1.png) 

~~~~
<background type="solid">
	<color r="255" g="0"   b="51"/> 
</background>
~~~~


![alt text](https://github.com/GabrielArSouza/RayTracer/blob/master/imgs/saida2.png) 

~~~~
<background type="interpolation">
	<color r="255" g="255" b="51"/>  
      	<color r="255" g="0"   b="51"/>  
	<color r="255" g="0"   b="51"/>
	<color r="255" g="255" b="51"/>
</background>
~~~~

![alt text](https://github.com/GabrielArSouza/RayTracer/blob/master/imgs/saida3.png) 

### Color

* Required attibutes
	- `r` - The red value of RGB color
	- `g` - The green value of RGB color
	- `b` - The blue value of RGB color

#### Examples
~~~~
<color r="0"   g="0"   b="51"/> 
<color r="0"   g="255" b="51"/> 
<color r="255" g="255" b="51"/> 
<color r="255" g="0"   b="51"/>  
~~~~

### Camera

In the camera, you need to set the width and height of image> For this, use the tags `<width></width>` and `<height></height>`.
The required attributes in tags are `value`.

#### Example
~~~~
<camera>
	<width value="200"></width>
	<height value="100"></height>
</camera>
~~~~

###### © 2019 Souza, Gabriel A. Powered by [TinyXML-2](https://github.com/leethomason/tinyxml2)
