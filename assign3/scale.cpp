#include "scale.hpp"
#include "artist.hpp"
#include <string>

scale::scale() : drawer(), x_scale(0), y_scale(0) { }

scale::scale(artist* _artist, int _x_scale, int _y_scale) : drawer(_artist), x_scale(_x_scale), y_scale(_y_scale) { }

std::string scale::draw() {
	/*
	* The function that draws scaled ASCII art from original image
	*
	* return: std::string result: ASCII art string
	*/

	std::string result = "";
	int _width = get_artist()->get_width(), _height = get_artist()->get_height();
	char** _original_mapping = get_original_mapping();
	double x_factor, y_factor;
	
	x_factor = x_scale > 0 ? 1.0 * x_scale : 1.0 / abs(x_scale);
	y_factor = y_scale > 0 ? 1.0 * y_scale : 1.0 / abs(y_scale);

	// Allocate scaled mapping
	char** scaled_mapping = new char* [int(_height * y_factor)];
	for (int i = 0; i < int(_height * y_factor); i++) scaled_mapping[i] = new char[int(_width * x_factor)];

	// Scale original mapping using Nearest-neighbor method
	for (int y = 0; y < int(_height * y_factor); y++) {
		for (int x = 0; x < int(_width * x_factor); x++) {
			scaled_mapping[y][x] = _original_mapping[int(y / y_factor)][int(x / x_factor)];
		}
	}

	// Draw scaled ASCII art
	for (int y = 0; y < int(_height * y_factor); y++) {
		for (int x = 0; x < int(_width * x_factor); x++) {
			result += scaled_mapping[y][x];
		}
		result += "\n";
	}

	// Deallocate scaled mapping
	for (int i = 0; i < int(_height * y_factor); i++) delete[] scaled_mapping[i];
	delete[] scaled_mapping;

	return result;
}