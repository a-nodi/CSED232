#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include <string>

class student {
public:
	student();
	void input_info(std::string input_dept, std::string input_gender, 
		std::string input_name, int input_age);
	std::string get_dept();
	std::string get_gender();
	std::string get_name();
	int get_age();

private:
	std::string dept, name, gender;
	int age;
};

#endif