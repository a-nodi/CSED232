#pragma once
#include "artist.hpp"
#include "drawer.hpp"
#include <string>

class downsample : public drawer {
	public:
		downsample();
		downsample(artist*);
		std::string draw();
};