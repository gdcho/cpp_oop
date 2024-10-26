#include <algorithm>
#include <iostream>
#include <list>

using namespace std;
int fib()
{
	static int a = 0, b = 1;
	int c = a + b;
	a = b;
	b = c;
	return a;
}

struct Fib
{
	int a, b;
	Fib(): a{0}, b{1} {}
	int next() {
		int c = a + b;
		a = b;
		b = c;
		return a;
	}
};

class Fibonacci
{
private:
	int a, b;
public:
	Fibonacci(): a{0}, b{1} { }
	int operator()() {
		int c = a + b;
		a = b;
		b = c;
		return a;
	}
};

bool isDivisibleBy(int x, int divisor){
    return x/divisor;
}

bool isDivisibleBy5(int x){
    return x/5;
}

bool isDivisibleBy10(int x){
    return x/10;
}

struct is_divisible_by
{
	int divisor;
	is_divisible_by(int d): divisor{d} {}
	bool operator()(int number) const { // const no change to divisor
		return number % divisor == 0;
	}
};

// template<class T>
// struct is_div_by
// {
// 	T divisor;
// 	is_div_by(T d) : divisor{d} {}
// 	bool operator()(T n) const {
// 		return n % divisor == 0;
// 	}
// };

int main()
{
	cout << fib() << endl;
	cout << fib() << endl;
    cout << fib() << endl;
    cout << fib() << endl;
    cout << fib() << endl;
    cout << fib() << endl;
	cout << fib() << endl << endl;

	Fib f1, f2;
	cout << f1.next() << endl;
	cout << f1.next() << endl;
	cout << f1.next() << endl;
	cout << f2.next() << endl << endl;

	Fibonacci final1;
	cout << final1() << endl;
	cout << final1() << endl;
	cout << final1() << endl;
	cout << final1() << endl;
	cout << final1() << endl << endl;

	is_divisible_by div5(5); // function object
//	cout << div5(5) << endl;// returns true 5/5
//	cout << div5(11) << endl;// returns false 11/5

	list<int> l = { 2, 4, 10 };
	list<int>::iterator it = find_if(l.begin(), l.end(), div5);
	cout << *it << endl;

	// is_div_by<int>div10(10);
	// cout << div10(10) << endl;
}

