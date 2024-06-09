#pragma once
#include <vector>
#include "artist.hpp"

class sobely : public artist {
	public:
		sobely();
		sobely(int, int, const std::vector<int>&);
		virtual ~sobely();
		char mapper(int, int);
};