#include "classic.hpp"
#include <vector>

// classic::classic() : artist() { }

classic::classic(int _width, int _height, const std::vector<int>& _image_data) : artist(_width, _height, _image_data) { }

classic::~classic() { }

char classic::mapper(int x, int y) {
	/*
	* The function that converts pixel value to ASCII code using classic mapping
	*
	* param: int x: x-coordinate
	* param: int y: y-coordinate
	*
	* return: char value: "classic" result
	*/

	const char pixel_table[16] = { '@', '&', '%', 'W', 'X', 'A', 'H', 'O', 'T', '*', '^', '+', '-', '.', ' ', ' ' };
	int value = get_pixel(x, y) / 17;

	return pixel_table[value];
}