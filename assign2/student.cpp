#include <string>
#include "student.hpp"

student::student() {
	/*
	* Defalut constructor
	*/

	// Initialize member variables
	dept = "";
	name = "";
	gender = "";
	age = 0;

	return;
}

void student::input_info(std::string input_dept, std::string input_gender, 
	std::string input_name, int input_age) {
	/*
	* The function that receives student info
	* 
	* param: string input_dept : Received department
	* param: string input_gender : Received gender
	* param: string input_name : Received name
	* param: int input_age : Received age
	* 
	* return: void
	*/

	dept = input_dept;
	gender = input_gender;
	name = input_name;
	age = input_age;

	return;
}

std::string student::get_dept() {
	/*
	* The Accessor of Department
	* 
	* return: string dept: Department of student
	*/

	return dept;
}

std::string student::get_gender() {
	/*
	* The Accessor of Gender
	*
	* return: string gender: Gender of student
	*/

	return gender;
}

std::string student::get_name() {
	/*
	* The Accessor of Name
	*
	* return: string name: Name of student
	*/

	return name;
}

int student::get_age() {
	/*
	* The Accessor of Age
	*
	* return: int age: Age of student
	*/

	return age;
}
