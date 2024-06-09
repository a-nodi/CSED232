#include "drawer.hpp"
#include "artist.hpp"
#include <string>

drawer::drawer() : original_mapping(NULL) { }

drawer::drawer(artist* _artist) {
	artist_instance = _artist;
	original_mapping = NULL;

	// Allocate original ASCII image
	original_mapping = new char*[_artist->get_height()];
	for (int i = 0; i < _artist->get_height(); i++) original_mapping[i] = new char[_artist->get_width()];

	// Map ASCII code to pixels of ASCII image
	for (int y = 0; y < _artist->get_height(); y++) {
		for (int x = 0; x < _artist->get_width(); x++) {
			original_mapping[y][x] = _artist->mapper(x, y);
		}
	}
}

drawer::~drawer() {
	// Deallocate original mapping
	for (int i = 0; i < artist_instance->get_height(); i++) {
		delete[] original_mapping[i];
	}

	delete[] original_mapping;

	// Deallocate artist_instance
	delete artist_instance;
}

std::string drawer::draw() {
	/*
	* The function that draws ASCII art from original image
	*
	* return: std::string result: ASCII art string
	*/

	std::string result = "";
	int _width = get_artist()->get_width(), _height = get_artist()->get_height();
	char** _original_mapping = get_original_mapping();

	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			result += original_mapping[y][x];
		}
		result += "\n";
	}

	return result;
}