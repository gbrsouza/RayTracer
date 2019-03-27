#include "raster.h"

Raster::Raster (Canvas * canvas)
{ this->canvas = canvas; }

Raster::Raster (Canvas * canvas, std::string filename)
{
	this->canvas = canvas;
	this->filename = filename;
}

void Raster::draw ()
{
	uint * image = this->canvas->get_image();

	std::ofstream myfile;
 	
 	myfile.open (this->filename + OUTPUT_EXTENSION);
  	myfile << OUTPUT_INDEX << "\n";
  	myfile << this->canvas->get_width() << " " 
  		   << this->canvas->get_heigth() << "\n";
  	myfile << MAX_COLOR_VALUE << "\n";

  	for (uint i = 0; i < this->canvas->get_size_canvas(); i+=VALUES_PER_PIXEL)
  	{
  		for (int j=0; j < VALUES_PER_PIXEL; j++)
  			myfile << image[(i+j)] << " ";
  		myfile << "\n";
  	}

	myfile.close();
}