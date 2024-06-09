#ifndef LIST_HPP_
#define LIST_HPP_

#include <string>
#include "student.hpp"
#include "node.hpp"

class list {
public:
	list();
	~list();

	bool is_dept_full();
	bool is_dept_exist(std::string dept);
	bool is_dept_member_full(std::string dept);
	bool is_student_exist(std::string dept, std::string gender, std::string name, int age);
	
	void save_node(node*);
	void delete_node(node*);
	node* find_node(std::string dept, std::string gender, std::string name, int age);
	void sort(std::string metric);
	node* get_head();
	
private:
	int count, dept_cnt;
	std::string dept[9];
	int dept_member_num[9];
	node* head;

	node* find_parent(node* input_node);
	node* merge_sort(node* _head, int length, std::string metric);
	node* merge(node* left_partition, node* right_partition, std::string metric);
	node* pop_first(node** _head);
};
#endif