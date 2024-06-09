#include <iostream>
#include <string>

using namespace std;

string add_digit(string digit, string number) {
	/*
	* :Description:
	* The function that concatenate digit and number.
	* 
	* :param:
	* string digit: Digit
	* string number: Number
	* 
	* :return:
	* string number (digit + number): Concatenated number
	*/

	return digit + number;
}

string dec_to_bin(int dec_num) {
	/*
	* :Description:
	* The function that convert decimal number to binary number.
	*
	* :param:
	* int dec_num: Decimal number that will be converted to binary number
	*
	* :return:
	* string binary_num: Binary number that have been converted from dec_num
	*/

	string bin_num = ""; // Binary number converted from decimal number
	int digit_value; // Digit value that will be converted to binary
	string bin_digit = ""; // Converted binary digit

	// Exception handling when dec_num is 0
	if (dec_num == 0) {
		return "0";
	}

	// Convert decimal number to binary number
	while (dec_num > 0) {
		digit_value = dec_num % 2; // Get digit value
		bin_digit = to_string(digit_value); // Convert decimal value to binary
		bin_num = add_digit(bin_digit, bin_num); // Write digit
		dec_num /= 2; // Move to next digit
	}

	return bin_num;
}

string dec_to_oct(int dec_num) {
	/*
	* :Description:
	* The function that convert decimal number to octal number.
	*
	* :param:
	* int dec_num: Decimal number that will be converted to octal number
	*
	* :return:
	* string oct_num: Octal number that have been converted from dec_num
	*/

	string oct_num = ""; // Octal number converted from decimal number
	int digit_value; // Digit value that will be converted to octal
	string oct_digit = ""; // Converted octal digit

	// Exception handling when dec_num is 0
	if (dec_num == 0) {
		return "0";
	}

	// Convert decimal number to octal number
	while (dec_num > 0) {
		digit_value = dec_num % 8; // Get digit value
		oct_digit = to_string(digit_value); // Convert decimal value to octal
		oct_num = add_digit(oct_digit, oct_num); // Write digit
		dec_num /= 8; // Move to next digit
	}

	return oct_num;
}

string dec_to_hex(int dec_num) {
	/*
	* :Description:
	* The function that convert decimal number to hexadecimal number.
	*
	* :param:
	* int dec_num: Decimal number that will be converted to hexadecimal number
	*
	* :return:
	* string hex_num: Hexadecimal number that have been converted from dec_num
	*/

	string hex_num = ""; // Hexadicimal string converted from decimal number
	string dec_to_hex_table[16] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" }; // Decimal-to-hexadecimal Table
	int digit_value; // Digit value that will be converted to hexadecimal
	string hex_digit = ""; // Converted hexadecimal digit

	// Exception handling when dec_num is 0
	if (dec_num == 0) {
		return "0";
	}

	// Convert decimal number to hexadecimal number
	while (dec_num > 0) {
		digit_value = dec_num % 16; // Get digit value
		hex_digit = dec_to_hex_table[digit_value]; // Convert decimal value to hexadecimal
		hex_num = add_digit(hex_digit, hex_num); // Write digit
		dec_num /= 16; // Move to next digit
	}

	return hex_num;
}

int main() {
	int num, base;

	// Read number and base
	cin >> num >> base;

	// Convert and write
	if (base == 2) { // Decimal-to-binary
		cout << dec_to_bin(num);
	}
	else if (base == 8) { // Decimal-to-octal
		cout << dec_to_oct(num);
	}
	else if (base == 16) { // Decimal-to-hexadecimal
		cout << dec_to_hex(num);
	}

	return 0;
}