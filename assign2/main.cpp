#include <iostream>
#include <string>
#include "student.hpp"
#include "node.hpp"
#include "list.hpp"

// Constant
const int ADD_STUDENT = 1;
const int DELETE_STUDENT = 2;
const int PRINT_STUDENT_LIST = 3;
const int PIVOT_TABLE = 4;
const int EXIT = 5;

const int DEPT = 1;
const int GENDER = 2;
const int DEPT_AND_GENDER = 3;

const int AVERAGE = 1;
const int MAX = 2;
const int MIN = 3;


// Function prototype
void print_menu();
void print_category();
void print_function();
void print_dept_pivot_table(list* student_list, int mode);
void print_gender_pivot_table(list* student_list, int mode);
void print_dept_and_gender_pivot_table(list* student_list, int mode);
bool is_selection_in_range(int selection);
bool is_sub_selection_in_range(int sub_selection);
bool is_all_uppercase(std::string dept);
bool is_all_alphabet(std::string dept);
bool is_gender_valid(std::string gender);
bool is_age_in_range(int age);


int main() {
	// Interface variables
	int selection, category_selection, function_selection;
	bool is_exception_throwed = false;

	// Student info variables
	std::string dept, gender, name;
	int age;

	// List related variables
	node* temp = NULL;
	list student_list = list();

	// Set decimal point
	std::cout << std::fixed;
	std::cout.precision(1);

	while (1) {
		print_menu(); // Print menu
		
		// Read selection
		while (1) {
			std::cin >> selection;

			if (std::cin.fail()) { // Exception: Selection is not integer
				std::cout << "Invalid selection. Please try again." << std::endl
				          << "Selection: "; // Exception message
				
				// Clear cin buffer and return cin flag to normal
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
			else if (!is_selection_in_range(selection)) { // Exception: Selection is not in range from 1 to 5
				std::cout << "Selection out of range. Please try again." << std::endl
					      << "Selection: "; // Exception message

				// Clear cin buffer
				std::cin.ignore(INT_MAX, '\n');
			}
			else { // Vaild input
				break;
			}
		}

		// Clear cin buffer and return cin flag to normal
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		if (selection == ADD_STUDENT) { // Selection is Add student
			
			// Read student info
			std::cout << "Dept: ";
			std::getline(std::cin, dept);
			std::cout << "Gender: ";
			std::getline(std::cin, gender);
			std::cout << "Name: ";
			std::getline(std::cin, name);
			std::cout << "Age: ";
				
			while (1) {
				std::cin >> age;

				if (std::cin.fail()) { // Exception: Age is not integer
					std::cout << "Invalid Age. Please try again." << std::endl
							  << "Age: "; // Exception message

					// Clear cin buffer and return cin flag to normal
					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');
				}
				else { // Valid input
					break;
				}
			}

			// Clear cin buffer and return cin flag to normal
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');

			// Exception handling
			if (student_list.is_dept_full() && !student_list.is_dept_exist(dept)) { // Exception: Number of dept is greater than 9
				std::cout << "Cannot Add dept more than 9" << std::endl; // Exception message
				is_exception_throwed = true;
			}
			
			if (student_list.is_dept_member_full(dept)) { // Exception: Number of member in each dept is greater than 10000
				std::cout << "Cannot Add more member to dept " << dept << std::endl; // Exception message
				is_exception_throwed = true;
			}

			if (!is_all_uppercase(dept)) { // Exception: Some character that consists dept string is not uppercase
				std::cout << "Dept should be all uppercase" << std::endl; // Exception message
				is_exception_throwed = true;
			}

			if (!is_all_alphabet(dept)) { // Exception: Some character that consists dept string is not alphabet
				std::cout << "Dept should be all alphabet" << std::endl; // Exception message
				is_exception_throwed = true;
			}

			if (!is_gender_valid(gender)) { // Exception: Gender is not F or M
				std::cout << "Invalid gender" << std::endl; // Exception message
				is_exception_throwed = true;
			}

			if (!is_all_alphabet(name)) { // Exception: Some character that consists name string is not alphabet
				std::cout << "Name should be all alphabet" << std::endl; // Exception message
				is_exception_throwed = true;
			}

			if (!is_age_in_range(age)) { // Exception: Age is not in range from 18 to 30
				std::cout << "Age out of range" << std::endl; // Exception message
				is_exception_throwed = true;
			}

			if (student_list.is_student_exist(dept, gender, name, age)) { // Exception: Student already exist
				std::cout << "The student already exist" << std::endl; // Exception message
				is_exception_throwed = true;
			}

			if(!is_exception_throwed) { // No Exception has been thrown
				
				temp = new node(dept, gender, name, age); // Allocate new node
				student_list.save_node(temp); // Save node into list

				std::cout << "A student is added in table!" << std::endl; // Success message
			}

			is_exception_throwed = false;
		}
		else if (selection == DELETE_STUDENT) { // Selection is Delete student
			
			// Read student info
			std::cout << "Dept: ";
			std::getline(std::cin, dept);
			std::cout << "Gender: ";
			std::getline(std::cin, gender);
			std::cout << "Name: ";
			std::getline(std::cin, name);
			std::cout << "Age: ";

			while (1) {
				std::cin >> age;

				if (std::cin.fail()) { // Exception: Age is not integer
					std::cout << "Invalid Age. Please try again" << std::endl
							  << "Age: "; // Exception message

					// Clear cin buffer and return cin flag to normal
					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');
				}
				else { // Valid input
					break;
				}
			}
			
			// Clear cin buffer and return cin flag to normal
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');

			// Exception handling
			if (!is_all_uppercase(dept)) { // Exception: Some character that consists dept string is not uppercase
				std::cout << "Dept should be all uppercase" << std::endl; // Exception message
				is_exception_throwed = true;
			}

			if (!is_all_alphabet(dept)) { // Exception: Some character that consists dept string is not alphabet
				std::cout << "Dept should be all alphabet" << std::endl; // Exception message
				is_exception_throwed = true;
			}

			if (!is_gender_valid(gender)) { // Exception: Gender is not F or M
				std::cout << "Invalid gender" << std::endl; // Exception message
				is_exception_throwed = true;
			}

			if (!is_all_alphabet(name)) { // Exception: Some character that consists name string is not alphabet
				std::cout << "Name should be all alphabet" << std::endl; // Exception message
				is_exception_throwed = true;
			}

			if (!is_age_in_range(age)) { // Exception: Age is not in range from 18 to 30
				std::cout << "Age out of range" << std::endl; // Exception message
				is_exception_throwed = true;
			}

			if (!student_list.is_student_exist(dept, gender, name, age)) { // Exception: Student doesn't exist
				std::cout << "Can't Delete it" << std::endl; // Exception message
				is_exception_throwed = true;
			}
			
			if (!is_exception_throwed) { // No exception has been thrown

				temp = student_list.find_node(dept, gender, name, age); // Find target node
				student_list.delete_node(temp); // Delete target node

				std::cout << "Deleted!" << std::endl; // Success message
			}

			is_exception_throwed = false;
		}
		else if (selection == PRINT_STUDENT_LIST) { // Selection is Print student list
			student_list.sort("Dept"); // Sort student list into 
			std::cout << "Dept\tGender\tName\tAge" << std::endl; // Print index

			// Print each student's info
			for (node* cur_node = student_list.get_head();
				cur_node != NULL; cur_node = cur_node->get_next()) {
				std::cout << cur_node->get_data().get_dept() << "\t" << cur_node->get_data().get_gender() << "\t"
						  << cur_node->get_data().get_name() << "\t" << cur_node->get_data().get_age() << std::endl;
			}

		}
		else if (selection == PIVOT_TABLE) { // Selection is Pivot table
			// Read category selection
			while (1) {
				print_category();
				std::cin >> category_selection;

				if (std::cin.fail()) { // Exception: Category selection is not integer
					std::cout << "Invalid selection. Please try again." << std::endl
						      << "Selection: "; // Exception message

					// Clear cin buffer and return cin flag to normal
					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');
				}
				else if (!is_sub_selection_in_range(category_selection)) { // Exception: Category selection is not in range from 1 to 3
					std::cout << "Selection out of range. Please try again." << std::endl
						      << "Selection: "; // Exception message

					// Clear cin buffer
					std::cin.ignore(INT_MAX, '\n');
				}
				else { // Valid input
					break;
				}
			}

			// Read function selection
			while (1) {
				print_function();
				std::cin >> function_selection;

				if (std::cin.fail()) { // Exception: Function selection is not integer
					std::cout << "Invalid selection. Please try again." << std::endl
						      << "Selection: "; // Exception message

					// Clear cin buffer and return cin flag to normal
					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');
				}
				else if (!is_sub_selection_in_range(function_selection)) { // Exception: Function selection is not in range from 1 to 3
					std::cout << "Selection out of range. Please try again." << std::endl
						      << "Selection: "; // Exception message

					// Clear cin buffer
					std::cin.ignore(INT_MAX, '\n');
				}
				else { // Valid input
					break;
				}
			}

			if (category_selection == DEPT) { // Category selection is dept
				student_list.sort("Dept"); // Sort student list in order of dept
				print_dept_pivot_table(&student_list, function_selection); // Print pivot table
			}
			else if (category_selection == GENDER) { // Category selection is gender
				student_list.sort("Gender"); // Sort student list in order of gender
				print_gender_pivot_table(&student_list, function_selection); // Print pivot table
			}
			else if (category_selection == DEPT_AND_GENDER) { // Category selection is dept and gender
				student_list.sort("Dept"); // Sort student list in order of dept and gender
				print_dept_and_gender_pivot_table(&student_list, function_selection); // Print pivot table
			}
			
		}
		else if (selection == EXIT) { // Selection is Exit
			std::cout << "Exit!" << std::endl; // Success message
			break;
		}
	}

	return 0;
}

void print_menu() {
	/*
	* The function that prints menu
	* 
	* return: void
	*/

	std::cout << "----------MENU----------\n"
	 	      << "1. Add a student\n"
	 	      << "2. Delete a student\n"
	      	  << "3. Print the student's list\n"
	 	      << "4. Pivot Table\n"
	 	      << "5. Exit\n"
	 	      << "------------------------\n"
	  	      << "Selection: ";
	
	return;
}

void print_category() {
	/*
	* The function that prints category menu
	* 
	* return: void
	*/

	std::cout << "----------Function----------\n"
		      << "1. Dept\n"
	      	  << "2. Gender\n"
		      << "3. Dept and Gender\n"
		      << "----------------------------\n"
		      << "Selection: ";

	return;
}

void print_function() {
	/*
	* The function that prints function menu
	* 
	* return: void
	*/

	std::cout << "----------Function----------\n"
		      << "1. Average\n"
		      << "2. Max\n"
		      << "3. Min\n"
		      << "-----------------------------\n"
		      << "Selection: ";

	return;
}

void print_dept_pivot_table(list* student_list, int mode) {
	/*
	* The function that prints pivot table in order in dept
	* Requirement: student list must be sorted in order in dept
	* 
	* param: list* student_list : Pointer of student list 
	* param: int mode : Pivot function mode
	* 
	* return: void
	*/

	int count; // Dept member counter
	double value; // Function value
	std::string current_dept = ""; // Dept
	node* temp = student_list->get_head(); // Temporary node

	// Print pivot index 
	if (mode == AVERAGE) std::cout << "Dept\tAverage" << std::endl;
	else if (mode == MAX) std::cout << "Dept\tMax" << std::endl;
	else if (mode == MIN) std::cout << "Dept\tMIN" << std::endl;
	else return; // Wrong pivot input

	while (temp != NULL) { // Walk all nodes in student list
		
		// Initialize variables on each dept
		count = 0;
		if (mode == MIN) value = 100.0;
		else value = 0.0;
		current_dept = temp->get_data().get_dept();
		
		while (current_dept == temp->get_data().get_dept()) { // While walking in current dept
			if (mode == AVERAGE) {
				value += temp->get_data().get_age();
			}
			else if (mode == MAX) {
				value = temp->get_data().get_age() > value ? temp->get_data().get_age() : value; // Choose max
			}
			else if (mode == MIN) {
				value = temp->get_data().get_age() < value ? temp->get_data().get_age() : value; // Choose min
			}

			// move to next node
			temp = temp->get_next();
			count++;

			if (temp == NULL) break; // Node ends
		}

		if (mode == AVERAGE) value /= count; // Calculate average
		std::cout << current_dept << "\t" << value << std::endl; // Print pivot value
	}

	return;
}

void print_gender_pivot_table(list* student_list, int mode) {
	/*
	* The function that prints pivot table in order in gender
	* Requirement: student list must be sorted in order in gender
	*
	* param: list* student_list : Pointer of student list
	* param: int mode : Pivot function mode
	*
	* return: void
	*/

	int count; // Dept member counter
	double value; // Function value
	std::string current_gender = ""; // Gender
	node* temp = student_list->get_head(); // Temporary node

	// Print pivot index 
	if (mode == AVERAGE) std::cout << "Gender\tAverage" << std::endl;
	else if (mode == MAX) std::cout << "Gender\tMax" << std::endl;
	else if (mode == MIN) std::cout << "Gender\tMIN" << std::endl;
	else return; // Wrong pivot input

	while (temp != NULL) { // Walk all nodes in student list

		// Initialize variables on each dept
		count = 0;
		if (mode == MIN) value = 100.0;
		else value = 0.0;
		current_gender = temp->get_data().get_gender();

		while (current_gender == temp->get_data().get_gender()) { // While walking in current gender
			if (mode == AVERAGE) {
				value += temp->get_data().get_age();
			}
			else if (mode == MAX) {
				value = temp->get_data().get_age() > value ? temp->get_data().get_age() : value; // Choose max
			}
			else if (mode == MIN) {
				value = temp->get_data().get_age() < value ? temp->get_data().get_age() : value; // Choose min
			}

			// move to next node
			temp = temp->get_next();
			count++;

			if (temp == NULL) break; // Node ends
		}
		if (mode == AVERAGE) value /= count; // Calculate average
		std::cout << current_gender << "\t" << value << std::endl; // Print pivot value
	}

	return;
}

void print_dept_and_gender_pivot_table(list* student_list, int mode) {
	/*
	* The function that prints pivot table in order in dept and gender
	* Requirement: student list must be sorted in order in dept and gender
	*
	* param: list* student_list : Pointer of student list
	* param: int mode : Pivot function mode
	*
	* return: void
	*/

	int count; // Dept member counter
	double value; // Function value
	std::string current_dept = ""; // Dept
	std::string current_gender = ""; // Gender
	node* temp = student_list->get_head(); // Temporary node

	// Print pivot index 
	if (mode == AVERAGE) std::cout << "Dept\tGender\tAverage" << std::endl;
	else if (mode == MAX) std::cout << "Dept\tGender\tMax" << std::endl;
	else if (mode == MIN) std::cout << "Dept\tGender\tMIN" << std::endl;
	else return; // Wrong pivot input

	while (temp != NULL) { // Walk all nodes in student list

		// Initialize variables on each dept
		count = 0;
		if (mode == MIN) value = 100.0;
		else value = 0.0;
		current_dept = temp->get_data().get_dept();
		current_gender = temp->get_data().get_gender();

		while (current_dept == temp->get_data().get_dept() && 
			current_gender == temp->get_data().get_gender()) { // While walking in current dept and gender
			if (mode == AVERAGE) {
				value += temp->get_data().get_age();
			}
			else if (mode == MAX) {
				value = temp->get_data().get_age() > value ? temp->get_data().get_age() : value; // Choose max
			}
			else if (mode == MIN) {
				value = temp->get_data().get_age() < value ? temp->get_data().get_age() : value; // Choose min
			}

			// move to next node
			temp = temp->get_next();
			count++;

			if (temp == NULL) break; // Node ends
		}
		if (mode == AVERAGE) value /= count; // Calculate average
		std::cout << current_dept << "\t" << current_gender << "\t" << value << std::endl;  // Print pivot value
	}

	return;
}

bool is_selection_in_range(int selection) {
	/*
	* The fucntion that determine the selection is in range from 1 to 5
	* 
	* param: int selection : Menu selection number
	* 
	* return bool : True if the selection is in range. If not, false
	*/

	return 1 <= selection && selection <= 5;
}

bool is_sub_selection_in_range(int sub_selection) {
	/*
	* The fucntion that determine the selection is in range from 1 to 3
	*
	* param: int selection : Category selection number or function selection number
	*
	* return bool : True if the selection is in range. If not, false
	*/

	return 1 <= sub_selection && sub_selection <= 3;
}

bool is_all_uppercase(std::string s) {
	/*
	* The fucntion that determine the characters in given string is all uppercase
	*
	* param: string s : given string
	*
	* return bool : True if the characters in given string is all uppercase. If not, false
	*/

	for (char c : s) { // Walk all character in s
		if ('a' <= c && c <= 'z') { // Given character c is lowercase
			return false;
		}
	}

	return true;
}

bool is_all_alphabet(std::string s) {
	/*
	* The function that determine the characters in given string is all alphabet
	* 
	* param: string s: given string
	* 
	* return bool : True if the characters in given string is all alphabet. It not, false
	*/

	for (char c : s) { // Walk all charactor in s
		if (!('A' <= c && c <= 'Z' || 'a' <= c && c <= 'z')) { // Given character is not alphabet
			return false;
		}
	}
	
	return true;
}

bool is_gender_valid(std::string gender) {
	/*
	* The function that determine the given gender is valid
	*
	* param: string s: given gender
	*
	* return bool : True if the given gender is F or M. It not, false
	*/

	return gender == "F" || gender == "M";
}

bool is_age_in_range(int age){
	/*
	* The fucntion that determine the age is in range from 18 to 30
	*
	* param: int selection : Menu selection number
	*
	* return bool : True if the age is in range. If not, false
	*/

	return 18 <= age && age <= 30;
}
