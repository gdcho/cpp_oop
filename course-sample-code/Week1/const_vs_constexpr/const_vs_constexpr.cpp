#include <iostream>
#include <limits>

using namespace std;

int main()
{
	cout << numeric_limits<int>::max() << endl;
	int a = 1;
	int b = 2;
	cout << a << endl;
	a <<= 3;
	cout << a << endl;
	cout << (a |= b) << endl;

	int input;
	cin >> input;
	// This compiles.  A const never changes.
	const int constantinput = input;

	// This does not compile. A constexpr must be known at compile-time.
	//constexpr int constantinput2 = input;
	
	cout << constantinput << endl;
	return 0;
}