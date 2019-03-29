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

### Background

## Camera


###### © 2019 Souza, Gabriel A. Powered by [TinyXML-2](https://github.com/leethomason/tinyxml2)
