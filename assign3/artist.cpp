#include "artist.hpp"
#include <vector>

artist::artist() : width(0), height(0) { }

artist::artist(int _width, int _height, const std::vector<int>& _image_data) :
	width(_width), height(_height), image_data(_image_data) { }

artist::~artist() { }