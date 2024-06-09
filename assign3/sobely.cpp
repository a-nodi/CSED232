#include "sobely.hpp"
#include "artist.hpp"
#include <vector>

// sobely::sobely() : artist() { }

sobely::sobely(int _width, int _height, const std::vector<int>& _image_data) : artist(_width, _height, _image_data) { }

sobely::~sobely() { }

char sobely::mapper(int x, int y) {
	/*
	* The function that performs "sobely" operation using pixel value of given corrdinate
	*
	* param: int x: x-coordinate
	* param: int y: y-coordinate
	*
	* return: char value: "sobely" result
	*/

	int value = get_pixel(x, y);
	int below_value;
	if (y == get_height() - 1) return ' '; // Exception handling: Bottommost pixel doesn't have bottom pixel
	else {
		below_value = get_pixel(x, y + 1);
		if (abs(value - below_value) >= 50) return '-';
		else return ' ';
	}
}