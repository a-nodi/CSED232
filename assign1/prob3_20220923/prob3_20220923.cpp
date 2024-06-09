#include <iostream>
#include <string>

using namespace std;

bool is_bin(string num) {
	/*
	* :Description:
	* The function that discriminates whether the input number is binary or not.
	*
	* :param:
	* string num: The number to be discriminated
	* 
	* :return:
	* bool flag: The flag whether the number is binary or not
	*/

	bool flag = false;

	if (num[0] == '0' && num[1] == 'b') { // If prefix == "0b"
		flag = true;
	}
	return flag;
}

bool is_oct(string num) {
	/*
	* :Description:
	* The function that discriminates whether the input number is octal or not.
	*
	* :param:
	* string num: The number to be discriminated
	* 
	* :return:
	* bool flag: The flag whether the number is octal or not
	*/

	bool flag = false;
	
	if (num[0] == '0' && !(num[1] == 'b' || num[1] == 'X')) { // If prefix == "0"
		flag = true;
	}

	return flag;
}

bool is_hex(string num) {
	/*
	* :Description:
	* The function that discriminates whether the input number is hexadecimal or not.
	*
	* :param:
	* string num: The number to be discriminated
	* 
	* :return:
	* bool flag: The Flag whether the number is hexadecimal or not
	*/
	bool flag = false;

	if (num[0] == '0' && num[1] == 'X') { // If prefix == "0X"
		flag = true;
	}

	return flag;
}

int bin_to_dec(string num) {
	/*
	* :Description:
	* The function that converts binary number to decimal.
	*
	* :param:
	* string num: The number that will be converted from binary to decimal
	* 
	* :return:
	* int dec_num: The number that converted to decimal
	*/

	int dec_num = 0;
	int digit;

	// Base convertion
	for (int i = 2; i < num.size(); i++) {
		digit = int(num[i] - '0');
		dec_num *= 2;
		dec_num += digit;
	}

	return dec_num;
}

int oct_to_dec(string num) {
	/*
	* :Description:
	* The function that converts octal number to decimal.
	*
	* :param:
	* string num: The number that will be converted from octal to decimal
	*
	* :return:
	* int dec_num: The number that converted to decimal
	*/

	int dec_num = 0;
	int digit;

	// Base convertion
	for (int i = 1; i < num.size(); i++) {
		digit = int(num[i] - '0');
		dec_num *= 8;
		dec_num += digit;
	}

	return dec_num;
}



int hex_to_dec(string num) {
	/*
	* :Description:
	* The function that converts hexadecimal number to decimal.
	*
	* :param:
	* string num: The number that will be converted from hexadecimal to decimal
	*
	* :return:
	* int dec_num: The number that converted to decimal
	*/

	int dec_num = 0;
	int digit;

	// Base convertion
	for (int i = 2; i < num.size(); i++) {
		if ('A' <= num[i] && num[i] <= 'F') { // If digit is A ~ F
			digit = int(num[i] - 'A' + 10);
		}
		else {
			digit = int(num[i] - '0'); // If digit is 0 ~ 9
		}
		dec_num *= 16;
		dec_num += digit;
	}
		
	return dec_num;
}

int main() {
	char operator_char;

	string operand1 = "";
	string operand2 = "";

	int dec_operand1 = 0;
	int dec_operand2 = 1;
	
	float result = 0;

	// Read opeartor and operands
	cin >> operator_char >> operand1 >> operand2;

	// Convert operand1 to decimal
	if (is_bin(operand1)) { // If it is binary number
		dec_operand1 = bin_to_dec(operand1);
	}
	else if (is_oct(operand1)) { // If it is octal number
		dec_operand1 = oct_to_dec(operand1);
	}
	else if (is_hex(operand1)) { // If it is hexadecimal number
		dec_operand1 = hex_to_dec(operand1);
	}

	// Convert operand2 to decimal
	if (is_bin(operand2)) { // If it is binary number
		dec_operand2 = bin_to_dec(operand2);
	}
	else if (is_oct(operand2)) { // If it is octal number
		dec_operand2 = oct_to_dec(operand2);
	}
	else if (is_hex(operand2)) { // If it is hexadecimal number
		dec_operand2 = hex_to_dec(operand2);
	}

	// Operate calculation
	if (operator_char == '+') {
		result = float(dec_operand1) + float(dec_operand2);
	}
	else if (operator_char == '-') {
		result = float(dec_operand1) - float(dec_operand2);
	}
	else if (operator_char == '*') {
		result = float(dec_operand1) * float(dec_operand2);
	}
	else if (operator_char == '/') {
		result = float(dec_operand1) / float(dec_operand2);
	}

	// Write calculation result
	cout.precision(3);
	cout << fixed << result;

	return 0;
}