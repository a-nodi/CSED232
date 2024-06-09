#include "iclassic.hpp"
#include <vector>

// iclassic::iclassic() : artist() { }

iclassic::iclassic(int _width, int _height, const std::vector<int>& _image_data) : artist(_width, _height, _image_data) { }

iclassic::~iclassic() { }

char iclassic::mapper(int x, int y) {
	/*
	* The function that converts pixel value to ASCII code using inverse classic mapping
	*
	* param: int x: x-coordinate
	* param: int y: y-coordinate
	*
	* return: char value: "inverse classic" result
	*/

	const char pixel_table[16] = { ' ', '.', '-', '+', '^', '*', 'T', 'O', 'H', 'A', 'X', 'W', '%', '&', '@', '@' };
	int value = get_pixel(x, y) / 17;
	
	return pixel_table[value];
}