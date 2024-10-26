#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int globalX = 10;

void function() {
	cout << "random function" << endl;
}

auto add (double a, double b)
{
	return a + b;
};

int main()
{
	double pi = 3.14;
	double body_temp = 37.0;

	[](){}(); //lambda that does nothing. Jeff's favorite C++ expression

	// 1. Basic lambda
	cout << "Example 1:\n";
	auto no_capture = []() { cout << "No capturing example 1" << endl; };
	no_capture();

	// 2. This basic lambda runs right away!
	cout << endl << "Example 2:\n";
	[](){ cout << "No capturing example 2" << endl; }();

	// 3. This lambda causes an error because it doesn't capture the variables
	cout << endl << "Example 3:\n";
	auto max = []() { return pi > body_temp ? pi : body_temp; };
	cout << max() << endl;

	// 4. This lambda works because it captures the variables
	cout << endl << "Example 4:\n";
	auto max2 = [=]() { return pi > body_temp ? pi : body_temp; };
	cout << max2() << endl;

	// 5. This lambda captures by value, but it can't change some
	//    captured by value!
	cout << "before: " << pi << endl;
	cout << endl << "Example 5:\n";
	auto change_value = [pi, body_temp] () {
		cout << "In example 5 lambda";
		pi = 6.28;
		body_temp = 5;
		return pi > body_temp ? pi : body_temp;
	};

	// 6. We CAN change variables captured by reference
	cout << endl << "Example 6:\n";
	auto change_value2 = [&] () { pi = 9.99; change_value(); function();};
	change_value2();
	cout << pi << endl;

	// 7. We can specify which values we capture by value
	cout << endl << "Example 7:\n";
	auto print_value = [pi, body_temp] ()
	{
		// But, you cannot access body_temp here
		cout << pi << endl;
		cout << body_temp << endl;
	};
	print_value();

	// 8. We can specify which values we capture by reference
	cout << endl << "Example 8:\n";
	auto mod_value = [&pi, &body_temp] ()
	{
		pi = 3.14;
		// But, you cannot access body_temp here
		body_temp = 37.1;
	};
	mod_value();
	cout << pi << endl;

	// 9. Mixed capture
	cout << endl << "Example 9:\n";
	auto mix_capture = [=, &body_temp] ()
	{
		body_temp = 37.1;
		cout << body_temp << endl;
		cout << pi << endl;
	};
	mix_capture();
	cout << body_temp << endl;

	// 10. Adding two values
	cout << endl << "Example 10:\n";
	auto add = [](double a, double b)
	{
		return a + b;
	};
	cout << add(pi, body_temp) << endl;
//
	// 11. Sorting a STL container
	cout << endl << "Example 11:\n";
	vector<double> scores;
	scores.push_back(50.0);
	scores.push_back(88.5);
	scores.push_back(70.4);
	//high to low. Or. low to high?
	sort(scores.begin(), scores.end(), [](double a, double b) { return (a > b); });
	for (auto it = scores.begin(); it < scores.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
	//high to low. Or. low to high?
	sort(scores.begin(), scores.end(), [](double a, double b)  { return (a <= b); });
	for (auto it = scores.begin(); it < scores.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;

	// 12. Using the mutable specifier
	cout << endl << "Example 12:\n";
	int value = 100;
	auto foo = [value] () mutable  {
		 cout << ++value << endl; // Compile error if we omit mutable
	};
	foo();
	 cout << value << endl; // Compile error if we omit mutable

	return 0;
}
