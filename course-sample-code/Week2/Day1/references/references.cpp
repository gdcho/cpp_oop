#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	int & b = a;
    cout << "value of a: " << a << "\n";
    cout << "value of b: " << b << "\n";

	b = 8;
    cout << "value of a: " << a << "\n";
    cout << "value of b: " << b << "\n";

	int & c = b;
	c = 4;

    cout << "value of b: " << a << "\n";
    cout << "value of c: " << b << "\n";

    cout << "address of a: " << &a << "\n";
    cout << "address of b: " << &b << "\n";
    cout << "address of c: " << &c << "\n";

	//c gets the value of d, it's not an alias of d
	int d = 999;
	c = d;
    cout << "value of a: " << c << "\n";
    cout << "value of b: " << b << "\n";
    cout << "value of c: " << c << "\n";
    cout << "value of d: " << d << "\n";

    cout << "address of a: " << &a << "\n";
    cout << "address of b: " << &b << "\n";
    cout << "address of c: " << &c << "\n";
    cout << "address of d: " << &d << "\n";

	return 0;
}