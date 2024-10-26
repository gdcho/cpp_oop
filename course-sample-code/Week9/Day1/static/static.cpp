#include <iostream>

using namespace std;

class A
{
private:
	int a;
public:
	A() : a{0} { cout << "A() created\n"; }
	~A() { cout << "A() destroyed\n"; }
	void increment() { a++; }
	void print() {cout << a << endl;}
};

class B
{
private:
	static A my_a;
public:
	static const double * pointer;
	B() { cout << "B() created\n"; }
	~B() { cout << "B() destroyed\n"; }
	void increment() { my_a.increment(); }
	void print() {my_a.print();}
};

const double * B::pointer = new double[3];
A B::my_a = A{};

int main()
{
	B b;
	B b2;
	cout << b.pointer[0] << " " << b.pointer[1] << " " << b.pointer[2] << endl;

	//modify public static pointer
	double * pt = const_cast<double *>(b.pointer);
	pt[0] = 1;
	pt[1] = 2;
	pt[2] = 3;
	cout << "b - " << b.pointer[0] << " " << b.pointer[1] << " " << b.pointer[2] << endl;
	cout << "b2 - " << b2.pointer[0] << " " << b2.pointer[1] << " " << b2.pointer[2] << endl;
	cout << "B:: - " << B::pointer[0] << " " << B::pointer[1] << " " << B::pointer[2] << endl;

	//modify private static class
	b.increment();
	b2.increment();
	cout << "b private a: "; b.print();
	cout << "b2 private a: "; b2.print();

	return 0;

}