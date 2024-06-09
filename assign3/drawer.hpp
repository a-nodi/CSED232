#pragma once
#include "artist.hpp"
#include <string>

class drawer {
	public:
		drawer();
		drawer(artist*);
		~drawer();
		virtual std::string draw();
		
	protected:
		artist* get_artist() const { return artist_instance; }
		char** get_original_mapping() const { return original_mapping; }
		void set_original_mapping(char** _original_mapping) { original_mapping = _original_mapping; }

	private:
		artist* artist_instance;
		char** original_mapping;
};