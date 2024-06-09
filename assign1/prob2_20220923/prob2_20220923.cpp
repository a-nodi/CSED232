#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

	char operator_char_array[7];
	string operator_string = "";
	float operand1, operand2;
	float result;

	// Read operator
	cin >> operator_char_array;
	operator_string = string(operator_char_array); // Convert char array to string

	// Operate calculation
	if (operator_string == "+") {
		cin >> operand1 >> operand2; // Read operands
		result = operand1 + operand2;
	}
	else if (operator_string == "-") {
		cin >> operand1 >> operand2; // Read operands
		result = operand1 - operand2;
	}
	else if (operator_string == "*") {
		cin >> operand1 >> operand2; // Read operands
		result = operand1 * operand2;
	}
	else if (operator_string == "/") {
		cin >> operand1 >> operand2; // Read operands
		result = operand1 / operand2;
	}
	else if (operator_string == "square") {
		cin >> operand1; // Read operand
		result = operand1 * operand1;
	}
	else if (operator_string == "sqrt") {
		cin >> operand1; // Read operand
		result = sqrt(operand1);
	}
	else {
		return 0;
	}

	// Write calculation result
	cout.precision(3);
	cout << fixed << result;

	return 0;
}