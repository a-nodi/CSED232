#pragma once
#include <vector>
#include "artist.hpp"

class sobelx : public artist {
	public:
		sobelx();
		sobelx(int, int, const std::vector<int>&);
		virtual ~sobelx();
		char mapper(int, int);
};