#pragma once
#include "artist.hpp"
#include "drawer.hpp"
#include <string>

class upsample : public drawer {
	public:
		upsample();
		upsample(artist*);
		std::string draw();

};