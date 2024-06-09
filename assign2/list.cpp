#include <string>
#include "student.hpp"
#include "list.hpp"
#include "node.hpp"

list::list() {
	/*
	* Default constructor
	*/
	
	// Initialize variables
	count = 0;
	dept_cnt = 0;
	head = NULL;

	for (int i = 0; i < 9; i++) {
		dept[i] = "";
		dept_member_num[i] = 0;
	}
	
	return;
}

list::~list() {
	/*
	* Destructor
	*/

	node* temp = head;
	node* temp_next;
	
	// Delete all node in student list
	while (temp != NULL) {
		temp_next = temp->get_next();
		delete_node(temp);
		temp = temp_next;
	}

	return;
}

bool list::is_dept_full() {
	/*
	* The fucntion that determines whether the list of department is full or not
	* 
	* return: bool : True if the list of department is full. It not, false  
	*/

	return dept_cnt >= 9;
}

bool list::is_dept_member_full(std::string input_dept) {
	/*
	* The function that determines the given department is full
	* 
	* param: string input_dept : Received department
	* 
	* return: bool : True if the number of members in given department is greater than or equal to 10000. If not, false
	*/

	int dept_index = 0;
	
	// Search index of given department in list
	for (int i = 0; i < dept_cnt; i++) {
		if (input_dept == dept[i]) {
			dept_index = i;
			break;
		}
	}

	return dept_member_num[dept_index] >= 10000;
}

bool list::is_dept_exist(std::string input_dept) {
	/*
	* The function that determines the given department exist in the list
	*
	* param: string input_dept : Received department
	*
	* return: bool : True if the given department is in the list. If not, false
	*/

	// Search given department in list
	for (int i = 0; i < dept_cnt; i++) {
		if (input_dept == dept[i]) {
			return true;
		}
	}
	
	return false;
}

bool list::is_student_exist(std::string dept, std::string gender, std::string name, int age) {
	/*
	* The function that determines the given student is exist in the list
	* 
	* param: string dept : Received department
	* param: string gender : Received gender
	* param: string name : Received name
	* param: int age : Received age
	* 
	* return: bool: True if the given student is exist in the list. If not, false
	*/

	// Search student that matches with the given student
	for (node* temp = head; temp != NULL; temp = temp->get_next()) {
		if (temp->get_data().get_dept() == dept &&
			temp->get_data().get_gender() == gender &&
			temp->get_data().get_name() == name &&
			temp->get_data().get_age() == age) {
			return true;
		}
	}

	return false;
}

void list::save_node(node* input_node) {
	/*
	* The function that saves the given node into the list
	* Requirement: There should be no duplicate nodes in the list
	* 
	* param: node* input_node : Received node
	* 
	* return: void
	*/

	node* temp = NULL;

	// Add new dept to list of dept
	if (!is_dept_exist(input_node->get_data().get_dept())) {
		for (int i = 0; i < 9; i++) {
			if (dept[i] == "") {
				dept[i] = input_node->get_data().get_dept();
				dept_cnt++;
				break;
			}
		}
	}

	// Count node and dept member
	count++;
	for (int i = 0; i < 9; i++) {
		if (input_node->get_data().get_dept() == dept[i]) {
			dept_member_num[i]++;
			break;
		}
	}

	// insert input_node as first node of list 
	if (head == NULL) temp = NULL;
	else temp = head;
	head = input_node;
	input_node->set_next(temp);
	
	return;
}

void list::delete_node(node* input_node) {
	/*
	* The function that deletes the given node into the list
	* Requirement: The given node should exist in the list
	* 
	* param: node* input_node : Received node
	*
	* return: void
	*/

	node* temp = NULL;

	// Count node and dept member
	count--;
	for (int i = 0; i < 9; i++) {
		if (input_node->get_data().get_dept() == dept[i]) {
			dept_member_num[i]--;
			if (dept_member_num[i] == 0) { // Delete empty department
				dept_cnt--;
				dept[i] = "";
			}
			break;
		}
	}

	// Delete input node
	if (input_node == head) {
		head = head->get_next();
		delete input_node;
	}
	else {
		temp = find_parent(input_node);
		temp->set_next(input_node->get_next());
		delete input_node;
	}

	return;
}

node* list::find_node(std::string dept, std::string gender, std::string name, int age) {
	/*
	* The function that finds node with given student info
	* 
	* param: string dept : Received department
	* param: string gender : Received gender
	* param: string name : Received name
	* param: int age : Received age
	* 
	* return: node* temp : The matching node
	*/

	// Walk list to find matching node
	for (node* temp = head; temp != NULL; temp = temp->get_next()) {
		if (temp->get_data().get_dept() == dept &&
			temp->get_data().get_gender() == gender &&
			temp->get_data().get_name() == name &&
			temp->get_data().get_age() == age) {
			return temp;
		}
	}

	return NULL;
}

void list::sort(std::string metric) { 
	/*
	* The function that sorts list with given sorting criteria
	* 
	* param: string metric : The sorting criteria
	* 
	* return: void
	*/

	head = merge_sort(head, count, metric); // head af sorted linked list
	return;
}

node* list::get_head() {
	/*
	* The accessor of head of student list
	* 
	* return: node* head: head of student list
	*/

	return head;
}

node* list::find_parent(node* input_node) {
	/*
	* The function that finds parent node of given node
	* 
	* param: node* input_node : Received node
	* 
	* return: node* temp : parent node of given node 
	*/

	// Walk to find parent node of given node
	for (node* temp = head; temp->get_next() != NULL; temp = temp->get_next()) {
		if (temp->get_next() == input_node) {
			return temp;
		}
	}
	return NULL;
}

node* list::merge_sort(node* _head, int length, std::string metric) {
	/*
	* The function that merge sorts the given linked list with the sorting criteria
	* 
	* param: node* _head: The head of (partial) linked list to be sorted
	* param: int length: The length of given linked list
	* param: string metric: sorting crieria
	* 
	* return: node* _head: The head of sorted (partial) linked list 
	*/

	node* left_partition = NULL;
	node* right_partition = NULL;
	node* temp = _head;
	int mid = (length + 1) / 2; // Calculate middle index of linked list

	if (length <= 1) return _head; // Empty or only 1 node in given linked list
	
	// Divid given linked list into two halves
	left_partition = _head;
	for (int i = 0; i < length; i++) {
		if (i == mid) {
			right_partition = temp;
			break;
		}
		temp = temp->get_next();
	}

	// De-link left partition and right partition
	temp = left_partition;
	for (int i = 0; i < length; i++) {
		if (temp->get_next() == right_partition) {
			temp->set_next(NULL);
			break;
		}
		temp = temp->get_next();
	}

	left_partition = merge_sort(left_partition, mid, metric); // merge sort left partition
	right_partition = merge_sort(right_partition, length - mid, metric); // merge sort right partition

	_head = merge(left_partition, right_partition, metric); // merge left partition and right partition
	
	return _head;
}

node* list::merge(node* left_partition, node* right_partition, std::string metric) {
	/*
	* The function that merges two given partitions with given sorting criteria
	* 
	* param: node* left_partition : Sorted linked ist
	* param: node* right_partition : Sorted linked list
	* param: string metric : Sorting criteria
	* 
	* return: node* _head: head of sorted and merged linked list
	*/

	node* _head = NULL;
	node* tail = NULL;
	node* temp = NULL;

	while (left_partition != NULL && right_partition != NULL) {
		// Choose which one to add to sorted linked list with sorting criteria
		if (metric == "Gender") {
			if (left_partition->get_data().get_gender() < right_partition->get_data().get_gender()) 
				temp = pop_first(&left_partition);
			else if (left_partition->get_data().get_gender() > right_partition->get_data().get_gender()) 
				temp = pop_first(&right_partition);
		}
		else if (metric == "Name") {
			if (left_partition->get_data().get_name() < right_partition->get_data().get_name()) 
				temp = pop_first(&left_partition);
			else if (left_partition->get_data().get_name() > right_partition->get_data().get_name())
				temp = pop_first(&right_partition);
		}
		else if (metric == "Age") {
			if (left_partition->get_data().get_age() < right_partition->get_data().get_age()) 
				temp = pop_first(&left_partition);
			else if (left_partition->get_data().get_age() > right_partition->get_data().get_age()) 
				temp = pop_first(&right_partition);
		}
		else { // metric == "Dept"
			if (left_partition->get_data().get_dept() < right_partition->get_data().get_dept()) 
				temp = pop_first(&left_partition);
			else if (left_partition->get_data().get_dept() > right_partition->get_data().get_dept()) 
				temp = pop_first(&right_partition);
			else if (left_partition->get_data().get_gender() < right_partition->get_data().get_gender()) 
				temp = pop_first(&left_partition);
			else if (left_partition->get_data().get_gender() > right_partition->get_data().get_gender()) 
				temp = pop_first(&right_partition);
			else if (left_partition->get_data().get_name() < right_partition->get_data().get_name()) 
				temp = pop_first(&left_partition);
			else if (left_partition->get_data().get_name() > right_partition->get_data().get_name()) 
				temp = pop_first(&right_partition);
			else if (left_partition->get_data().get_age() < right_partition->get_data().get_age()) 
				temp = pop_first(&left_partition);
			else if (left_partition->get_data().get_age() > right_partition->get_data().get_age()) 
				temp = pop_first(&right_partition);
		}

		// Set tail
		if (_head == NULL) { // Add node to head if head if empty
			_head = temp;
			tail = temp;
		}
		else {
			tail->set_next(temp);
			tail = temp;
		}

		// Make sure tail doesn't have next nodes
		tail->set_next(NULL);
	}

	// link leftover partition to linked list
	if (left_partition == NULL && tail == NULL) {
		_head = right_partition;
		tail = _head;
	}
	else if (right_partition == NULL && tail == NULL) {
		_head = left_partition;
		tail = _head;
	}
	else if (left_partition == NULL && tail != NULL) {
		tail->set_next(right_partition);
		for (node* cur_node = tail; cur_node != NULL; cur_node = cur_node->get_next()) tail = cur_node;
		tail->set_next(NULL);
	}
	else if (right_partition == NULL && tail != NULL) {
		tail->set_next(left_partition);
		for (node* cur_node = tail; cur_node != NULL; cur_node = cur_node->get_next()) tail = cur_node;
		tail->set_next(NULL);
	}

	return _head;
}

node* list::pop_first(node** _head) {
	/*
	* The function that pop out first node of given linked list
	* Requirement: given linked list must not be empty
	* 
	* param: node** _head : pointer of pointer of first node of given linked list
	* 
	* return: node* temp : pointer of first node
	*/

	node* temp;
	temp = *_head;
	(*_head) = temp->get_next();

	return temp;
}