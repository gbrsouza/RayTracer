#include "color.h"

Color::Color( color_t r , color_t g , color_t b )
{
	this->channels[0] = r;
	this->channels[1] = g;
	this->channels[2] = b;
}

Color::Color (const Color &clone)
{
	this->channels[0] = clone.channels[0];
	this->channels[1] = clone.channels[1];
	this->channels[2] = clone.channels[2];
}

Color& Color::operator= (const Color & rhs)
{
	for (int i=0; i < 3; ++i )
		*(channels+i) = *(rhs.channels+i);

	return *this;
}

bool Color::operator== (const Color & rhs)
{
	for (int i=0; i < 3; ++i)
		if (channels[i] != rhs.channels[i])
			return false;
		
	return true;
}

Color::~Color(){}

color_t * Color::get_color_value ()
{ return channels; }

std::string Color::to_string()
{
	return "rgb(" + std::to_string(channels[0]) + "," + std::to_string(channels[1])
			 + "," + std::to_string(channels[2]) + ")";
}

const Color& Color::get_color(std::string name_color)
{
	if (name_color.compare("red") == 0)
		return Color::RED;
	else if (name_color.compare("green") == 0)
		return Color::GREEN;
	else if (name_color.compare("blue") == 0)
		return Color::BLUE;
	else if (name_color.compare("black") == 0)
		return Color::BLACK;
	else if (name_color.compare("white") == 0)
		return Color::WHITE;
	else if (name_color.compare("yellow") == 0)
		return Color::YELLOW;
	else if (name_color.compare("pink") == 0)
		return Color::PINK;
	else if (name_color.compare("orange") == 0)
		return Color::ORANGE;
	else if (name_color.compare("boldgreen") == 0)
		return Color::BOLDGREEN;
	else if (name_color.compare("skyblue") == 0)
		return Color::SKYBLUE;
	else throw "Invalid color name";
}

const Color Color::RED(255,0,0);
const Color Color::GREEN(0, 255, 0);
const Color Color::BLUE(0, 0, 255);
const Color Color::BLACK(0,0,0);
const Color Color::WHITE(255,255,255);
const Color Color::YELLOW(255,255,0);
const Color Color::PINK(250, 91, 138);
const Color Color::ORANGE(254, 123, 33);
const Color Color::BOLDGREEN(34, 90, 14);
const Color Color::SKYBLUE(141, 207, 251);
