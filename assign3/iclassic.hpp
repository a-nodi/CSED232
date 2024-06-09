#pragma once
#include <vector>
#include "artist.hpp"

class iclassic : public artist {
	public:
		iclassic();
		iclassic(int, int, const std::vector<int>&);
		virtual ~iclassic();
		char mapper(int, int);

	private:

};