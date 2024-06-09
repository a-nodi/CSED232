#include <string>
#include "node.hpp"
#include "student.hpp"

node::node() {
	/*
	* Default constructor
	*/
	next = NULL;

	return;
}

node::node(std::string dept, std::string gender, std::string name, int age) {
	/*
	* Constructor
	* 
	* param: string dept : Received department
	* param: string gender : Received gender
	* param: string name : Received name
	* param: int age : Received age
	* 
	* return: void
	*/

	data.input_info(dept, gender, name, age); // Enter student info to data
	next = NULL;

	return;
}

void node::set_next(node* value) {
	/*
	* The mutator of current node's next node
	* 
	* param: node* value : Pointer of next node
	* 
	* return: void
	*/

	next = value;

	return;
}

student node::get_data() {
	/*
	* The accessor of student data
	* 
	* return: student data : student data
	*/

	return data;
}

node* node::get_next() {
	/*
	* The accessor of next node
	*
	* return: node* next : Pointer of next node
	*/
	return next;
}