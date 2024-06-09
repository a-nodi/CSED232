#include "parser.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

std::vector<int> parser::load_image(const char* _file_path) {
	/*
	* The function that loads image from given file
	* 
	* param: const char* _file_path: Path of given file
	* 
	* return: std::vector<int> image_data: Vector that contains integer image datas
	*/

	const char DELIMITER = '|';
	int front_cursor = 0, back_cursor = 0; // Used in string parsing 
	std::ifstream input_file;
	std::string raw_string = "";
	std::vector<int> image_data(0);

	// Open file
	input_file.open(_file_path);
	if (!input_file.is_open()) return image_data; // Exception handling: File didn't open 
	else getline(input_file, raw_string); // Read file
	
	// Parse data
	while (raw_string.size() - 1 >= back_cursor) { // Parse all data
		if (raw_string[back_cursor] == DELIMITER) { // Found Delimiter
			image_data.push_back(stoi(
				raw_string.substr(front_cursor, back_cursor - front_cursor)));
			front_cursor = back_cursor + 1; 
		}
		else if (raw_string.size() - 1 == back_cursor) { // Back cursor reached eof (No delimter exists but data exists)
			image_data.push_back(stoi(
				raw_string.substr(front_cursor, back_cursor + 1 - front_cursor)));
		}
		back_cursor++;
	}

	// Close file
	input_file.close();
	
	return image_data;
}

std::vector<std::string> parser::load_config(const char* _file_path) {
	/*
	* The Function that loads config data from given file
	* 
	* param: const char* _file path: Path of given file
	* 
	* return: std::vector<string> config_data: Vector that contains image config datas
	*/

	const char DELIMITER = '|';
	int front_cursor = 0, back_cursor = 0; // Used in string parsing 
	std::ifstream input_file;
	std::string raw_string = "";
	std::vector<std::string> config_data(0);

	input_file.open(_file_path);
	if (!input_file.is_open()) return config_data; // Exception handling: File didn't open 
	else getline(input_file, raw_string); // Read file

	while (raw_string.size() - 1 >= back_cursor) { // Parse all data
		if (raw_string[back_cursor] == DELIMITER) { // Found Delimiter
			config_data.push_back(raw_string.substr(front_cursor, back_cursor - front_cursor));
			front_cursor = back_cursor + 1;
		}
		else if (raw_string.size() - 1 == back_cursor) { // Back cursor reached eof (No delimter exists but data exists)
			config_data.push_back(raw_string.substr(front_cursor, back_cursor + 1 - front_cursor));
		}
		back_cursor++;
	}

	// Close file
	input_file.close();

	return config_data;
}

void parser::write_result(const char* _file_path, const std::string& _data) {
	/*
	* The function that writes file with given file path and data
	* 
	* param: const char* _file_path: Path of given file
	* param: const string& data: Given data to be written
	* 
	* return: void
	*/

	// Open file
	std::ofstream output_file;
	output_file.open(_file_path);
	output_file << _data;

	// Close file
	output_file.close();

	return;
}
