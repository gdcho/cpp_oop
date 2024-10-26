#include <iostream>

using namespace std;

class A
{
	private:
	int x;
	public:
	A() : x{0} { cout << "A()" << endl; }
	A(int x) : x{x} { cout << "A(" << x << ")" << endl; }
	int get_x() const { return x; }
	void set_x(int new_x) { x = new_x; }
};

class B : public A
{
public:
	B(): A() { cout << "B()" << endl; }

//	B(int x) {
//		cout << "B(" << get_x() << ")" << endl;
//	}

// Ideal way to pass data back to base calss A
//	B(int x) : A{x} // pass the x for base class to derived class
//	 {
//	 	cout << "B(" << get_x() << ")" << endl;
//	 }

//	// NO DON'T DO THIS
//	B(int x)
//	{
//		set_x(x);
//	 	cout << "B(" << get_x() << ")" << endl;
//	}

//	// error: member initializer 'x' does not name a non-static data member or base class
//	B(int x) : x{x}
//	 {
//	 	cout << "B(" << get_x() << ")" << endl;
//	 }
};


int main()
{
	A a;
	//B b;
	//B c{2};
	return 0;	
}