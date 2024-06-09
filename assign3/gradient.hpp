#pragma once
#include <vector>
#include "artist.hpp"

class gradient : public artist {
	public:
		gradient();
		gradient(int, int, const std::vector<int>&);
		virtual ~gradient();
		char mapper(int, int);
};