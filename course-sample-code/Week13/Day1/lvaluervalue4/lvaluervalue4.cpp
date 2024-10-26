#include <iostream>
int main() {
	int number = 10; // 10 is a rvalue

	10 = number; // Error because 10 is a rvalue
	(number + 1) = 20; // Error because (number + 1) is a rvalue

	int anotherNumber = 20;
	int result = number + anotherNumber; // (number + anotherNumber) is a rvalue

	&number = 20; // Error because &number is a rvalue

	return 0;
}
