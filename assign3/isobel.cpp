#include "isobel.hpp"
#include <vector>

isobel::isobel(int _width, int _height, const std::vector<int>& _image_data) : artist(_width, _height, _image_data) { }

isobel::~isobel() { }

char isobel::mapper(int x, int y) {
	/*
	* The function that performs "isobel" operation using pixel value of given corrdinate
	*
	* param: int x: x-coordinate
	* param: int y: y-coordinate
	*
	* return: char value: "gradient" result
	*/

	int value = get_pixel(x, y);
	int right_value, below_value;
	bool is_x_differ_50 = false, is_y_differ_50 = false;

	if (x != get_width() - 1) { // Not rightmost pixel
		right_value = get_pixel(x + 1, y);
		if (abs(value - right_value) >= 50) is_x_differ_50 = true;
	}
	if (y != get_height() - 1) { // Not bottommost pixel
		below_value = get_pixel(x, y + 1);
		if (abs(value - below_value) >= 50) is_y_differ_50 = true;
	}

	// Map pixel to ASCII code
	if (is_x_differ_50 && is_y_differ_50) return ' ';
	else if (is_x_differ_50) return ' ';
	else if (is_y_differ_50) return ' ';
	else return '@';
}
