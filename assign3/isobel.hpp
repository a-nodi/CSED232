#pragma once
#include <vector>
#include "artist.hpp"

class isobel : public artist {
public:
	isobel();
	isobel(int, int, const std::vector<int>&);
	virtual ~isobel();
	char mapper(int, int);
};
