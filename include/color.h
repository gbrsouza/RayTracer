#ifndef _COLOR_H_
#define _COLOR_H_

	#include <string>
	/**
	 * Type of a color channel
	 */
	typedef unsigned int color_t;

	/**
	 * @brief      Identifies each color channel. 
	 */
	enum channel_e : color_t {
		r = 0, //<! Red
		g = 1, //<! Green
		b = 2, //<! Blue
	};

	/**
	 * @brief A class for color object
	 * 
	 */
	class Color {

		public:
			
			static const Color RED;
			static const Color GREEN;
			static const Color BLUE;
			static const Color BLACK;
			static const Color WHITE;
			static const Color YELLOW;
			static const Color PINK;
			static const Color ORANGE;
			static const Color BOLDGREEN;
			static const Color SKYBLUE;

			/**
			 * The 3 channels: red, green and blue
			 */
			color_t channels [3];

			/**
			 * @brief      Constructs the object.
			 *
			 * @param[in]  r     The red value
			 * @param[in]  g     The green value
			 * @param[in]  b     The blue value
			 */
			Color( color_t r = 0, color_t g = 0, color_t b = 0);

			/**
			 * @brief      Constructs the object.
			 *
			 * @param[in]  clone  The clone
			 */
			Color (const Color &clone);

			/**
			 * @brief      Destroys the object.
			 */
			~Color();

			/**
			 * @brief      Assignment operator
			 *
			 * @param[in]  rhs   The right hand side
			 *
			 * @return     A new color equals rhs
			 */
			Color& operator= (const Color & rhs);

			/**
			 * @brief      Comparison operator
			 *
			 * @param[in]  rhs   The right hand side
			 *
			 * @return     True, if equals; false otherwise
			 */
			bool operator== (const Color & rhs);
		
			/**
			 * @brief Get the color value object
			 * 
			 * @return color_t* the unsigned int array
			 */
			color_t * get_color_value ();

			/**
			 * @brief Get the color object
			 * 
			 * @param name_color  the color name
			 * @return const Color&  the object of color
			 */
			const Color& get_color(std::string name_color);

			/**
			 * @brief description of class
			 * 
			 * @return std::string the description string
			 */
			std::string to_string();
	};

#endif