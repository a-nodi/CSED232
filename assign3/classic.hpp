#pragma once
#include <vector>
#include "artist.hpp"

class classic : public artist {
	public:
		classic();
		classic(int, int, const std::vector<int>&);
		virtual ~classic();
		char mapper(int, int);

	private:

};