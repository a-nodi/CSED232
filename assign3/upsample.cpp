#include "upsample.hpp"
#include "artist.hpp"
#include <string>

upsample::upsample() : drawer() { }

upsample::upsample(artist* _artist) : drawer(_artist) { }

std::string upsample::draw() {
	/*
	* The function that draws double upsampled ASCII art from original image 
	* 
	* return: std::string result: ASCII art string 
	*/
	
	std::string result = "";
	int _width = get_artist()->get_width(), _height = get_artist()->get_height();
	char** _original_mapping = get_original_mapping();
	
	// Allocate upsampled mapping
	char** upsampled_mapping = new char* [_height * 2];
	for (int i = 0; i <_height * 2; i++) upsampled_mapping[i] = new char[_width * 2];

	// Upsample original mapping using Nearest-neighbor method
	for (int y = 0; y < _height * 2; y++) {
		for (int x = 0; x < _width * 2; x++) {
			upsampled_mapping[y][x] = _original_mapping[y / 2][x / 2];
		}
	}

	// Draw ASCII art
	for (int y = 0; y < _height * 2; y++) {
		for (int x = 0; x < _width * 2; x++) {
			result += upsampled_mapping[y][x];
		}
		result += "\n";
	}

	// Deallocate upsampled mapping
	for (int i = 0; i < _height * 2; i++) delete[] upsampled_mapping[i];
	delete[] upsampled_mapping;

	return result;
}