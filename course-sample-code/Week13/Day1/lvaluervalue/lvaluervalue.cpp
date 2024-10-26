#include <iostream>
using namespace std;
int main()
{
	int i, j, *p;

	// Correct usage: the variable i is an lvalue and the literal 7 is a prvalue.
	i = 0;
//
//	// Incorrect usage: The left operand must be an lvalue (C2106).`j * 4` is a prvalue.
//	7 = i; // C2106
//	(j * 4) = 7; // C2106
//
//	// Correct usage: the dereferenced pointer is an lvalue.
//	*p = i;
//
//	const int ci = 7;
//	// Incorrect usage: the variable is a non-modifiable lvalue (C3892).
//	ci = 9; // C3892

	// Correct usage: the conditional operator returns an lvalue.
	((i < 3) ? i : j) = 11;
	cout << i << endl;
	cout << j << endl;

	return 0;
}