#include "downsample.hpp"
#include "artist.hpp"
#include <string>

downsample::downsample() : drawer() { }

downsample::downsample(artist* _artist) : drawer(_artist) { }

std::string downsample::draw() {
	/*
	* The function that draws half downsampled ASCII art from original image
	*
	* return: std::string result: ASCII art string
	*/

	std::string result = "";
	int _width = get_artist()->get_width(), _height = get_artist()->get_height();
	char** _original_mapping = get_original_mapping();

	// Allocate downsampled mapping
	char** downsampled_mapping = new char* [_height / 2];
	for (int i = 0; i < _height / 2; i++) downsampled_mapping[i] = new char[_width / 2];
	
	// Downsample original mapping using Nearest-neighbor method
	for (int y = 0; y < _height / 2; y++) {
		for (int x = 0; x < _width / 2; x++) {
			downsampled_mapping[y][x] = _original_mapping[2 * y][2 * x];
		}
	}

	// Draw ASCII art
	for (int y = 0; y < _height / 2; y++) {
		for (int x = 0; x < _width / 2; x++) {
			result += downsampled_mapping[y][x];
		}
		result += "\n";
	}

	// Deallocate upsampled mapping
	for (int i = 0; i < _height / 2; i++) delete[] downsampled_mapping[i];
	delete[] downsampled_mapping;

	return result;
}