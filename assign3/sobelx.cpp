#include "sobelx.hpp"
#include "artist.hpp"
#include <vector>

// sobelx::sobelx() : artist() { }

sobelx::sobelx(int _width, int _height, const std::vector<int>& _image_data) : artist(_width, _height, _image_data) { }

sobelx::~sobelx() { }

char sobelx::mapper(int x, int y) {
	/*
	* The function that performs "sobelx" operation using pixel value of given corrdinate
	* 
	* param: int x: x-coordinate
	* param: int y: y-coordinate
	* 
	* return: char value: "sobelx" result 
	*/

	int value = get_pixel(x, y);
	int right_value;
	if (x == get_width() - 1) return ' '; // Exception handling: Rightmost pixel doesn't have right pixel
	else {
		right_value = get_pixel(x + 1, y);
		if (abs(value - right_value) >= 50) return '|';
		else return ' ';
	}
}