#include <iostream>
#include <string>
/*
 * Try catch for classes
 */
using namespace std;

class A
{
public:
	A() { cout << "A() created\n"; }
	~A() { cout << "A() destroyed\n"; }

};

class B
{
public:
	B() { cout << "B() created\n"; }
	B(int) { cout << "B() being created\n"; throw "exception"; }
	~B() { cout << "B() destroyed\n"; }

};

class C : public A
{
private:
	B my_b;
public:
	C(int x) try : A(), my_b(x) //can try/catch on the constructor
	{
		cout << "C() created\n";
	}
	catch ( ... )
	{
		cout << "C not constructed!\n";
					throw;
	}

	~C() { cout << "C() destroyed\n"; }
};

int main()
{
	cout << "Making a B\n";
	B b;

	cout << "Making a C\n";
	C c(1); //throws error that's not caught
    //program terminates here
	cout << "Code not called because throw not caught" << endl;
	return 0;
}