#pragma once
#include <vector>

class artist{
	public:
		artist();
		artist(int, int, const std::vector<int>&);
		virtual ~artist();
		int get_width() const { return width; };
		int get_height() const { return height; };
		virtual char mapper(int, int) = 0;

	protected:
		
		int get_pixel(int x, int y) const { return image_data[x + width * y]; };

	private:
		int width, height;
		std::vector<int> image_data;
};

