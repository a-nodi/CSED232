#ifndef NODE_HPP_
#define NODE_HPP_

#include <string>
#include "student.hpp"

class node {
public:
	node();
	node(std::string dept, std::string gender, std::string name, int age);
	void set_next(node* value);
	student get_data();
	node* get_next();


private:
	student data;
	node* next;
};

#endif