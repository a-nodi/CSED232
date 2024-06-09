#pragma once
#include "artist.hpp"
#include "drawer.hpp"
#include <string>

class scale : public drawer {
	public:
		scale();
		scale(artist*, int, int);
		std::string draw();

	private:
		int x_scale, y_scale;
};