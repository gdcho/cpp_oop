#include <iostream>
using namespace std;

//function returns an r value
double get_average()
{
	double average = 0.0;
	// Calculates stuff
	return average; // 0 that's sent back is actually an rvalue
}
int main()
{
	int number = 10; //copies 10 into number assuming no copy elision/RVO
	int& numberRef = number; //create a reference to number via numberRef
	numberRef = 99;
    //int& numberRef2 = 10; //ERROR, can't assign rValue to lValue

	int&& rValueRef = 10; // OK, 10 is a rvalue
    //int&& rValueRef2 = number; // Error, number is an lvalue. rvalue reference can only hold rValue

	//rvalue reference can hold rvalue return type
	double&& rAverage = get_average(); // OK, get_average() is a rvalue

    //lvalue can hold rvalue return type
	double anotherNum = get_average();

	//Why use rvalue references? To avoid copies!
    number = 88; //lValue number copies 88
    rValueRef = 99; //rValueRef holds onto rValue temporary
    cout << rValueRef << endl;
}
