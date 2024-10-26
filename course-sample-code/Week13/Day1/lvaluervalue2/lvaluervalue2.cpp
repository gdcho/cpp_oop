#include <iostream>
#include <map>
using namespace std;
int main() {
	int number = 10; // number is an lvalue

	const int NAME_MAX = 20; // NAME_MAX is an lvalue

	int* numberPtr = &number; // numberPtr is an lvalue

	std::map<string, double> scoreMap;

	scoreMap["Lulu"] = 60.0; // scoreMap["Lulu"] is an lvalue ([] operator)
	
	return 0;
}
