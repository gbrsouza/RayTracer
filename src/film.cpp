#include "film.h"

void 
Film::add_sampler( Point2i pixel, 
                   Color24 color)
{
    int init_pixel = this->get_position_pixel(pixel.x(), pixel.y());
	for (int i=0; i < VALUES_PER_PIXEL; i++)
		this->image[init_pixel+i] = abs(color[i]);
}

void
Film::write_img()
{
    std::ofstream myfile;
 	
 	myfile.open (this->filename + OUTPUT_EXTENSION);
  	myfile << OUTPUT_INDEX << "\n";
  	myfile << this->dimensions.x() << " " 
  		   << this->dimensions.y() << "\n";
  	myfile << MAX_COLOR_VALUE << "\n";

  	for (uint i = 0; i < this->get_size(); i+=VALUES_PER_PIXEL){
  		
          for (uint j=0; j < VALUES_PER_PIXEL; j++)
  			myfile << image[(i+j)] << " ";
        
        myfile << "\n";
  	}

	myfile.close();
}

int 
Film::get_position_pixel( int x, int y )
{
	if ( (unsigned int) x > this->dimensions.x() || 
		 (unsigned int) y > this->dimensions.y() ||
		 (unsigned int) x < 1 ||
		 (unsigned int) y < 1)
		return 0;

	/**
	 * A imagem está armazena sequenciamente em um grande array
	 * de unsigned char. A ordem de inserção no array é linha por 
	 * linha. Cada pixel possui uma quantidade de valores definida
	 * na constante VALUES_PER_PIXEL. A expressão abaixo define a
	 * quantidade de caracteres necessários para representar uma 
	 * linha da imagem.
	 */
	int line_size = this->dimensions.x() * VALUES_PER_PIXEL;


	/**
	 * Com o valor do eixo x do pixel podemos encontrar a possição
	 * do array em que a linha onde o pixel se encontra começa. Como
	 * a representação do array começa em 0 é necessário diminuir 1
	 * do valor de x_axis recebido. A expressão abaixo encontra o 
	 * início da linha onde o pixel está.
	 */
	int init_line_of_pixel = (this->dimensions.y()-y) * line_size;


	/**
	 * Seguindo a lógica para encontrar o início da linha, agora 
	 * é necessário encontrar a posição onde começa o pixel. A 
	 * expressão abaixo realiza este cálculo.
	 */
	int init_pixel = init_line_of_pixel + (x * VALUES_PER_PIXEL) ;

	return init_pixel;
}