#include <iostream>

using namespace std;

//function returns lValue
int& function(int &num) {
    return num;
}

//function returns rValue
int function() {
    return 1;
}

int main() {

    //1: lValue and rValue function return types
    int x = 10;
    cout << "x address: " << &x << endl;
    cout << "x address from lValue return function: " << &function(x) << endl;
    //cout << &function(); //ERROR - non reference return functions return rValue

    //2: rValue references are lvalues
    int five = 5;
    int && fiveRef = move(five); //fiveRef is a rvalue reference, but itself is an lvalue
    //int && fiveRefRef = fiveRef; //complains can't assign lvalue to rvalue ref
    cout << "fiveRef address: " <<&fiveRef << endl << endl; //can only use & (address of) on lvalues

    //3: rvalue refs act like regular references but they're referencing an rvalue
    int num = 1; //rvalue 1 copied to num
    int && numRef = move(num); //convert num to rvalue assign to rvalue ref
    cout << num << endl;
    cout << numRef << endl;
    num = 5;
    //numRef is referencing rvalue version of num so numRef so it has same value as num
    cout << num << endl;
    cout << numRef << endl << endl;

    //4: move doesn't actually move...
    int n = 1;
    //int n1 = static_cast<int&&>(n); //same as move function
    int n1 = move(n); //converts n to an rvalue. int doesn't have move constructor so n is simply copied to n2
    cout << "1: " << n << endl;
    cout << "2: " << n1 << endl << endl;

    string hello = "hello";
    //string hello2 = static_cast<string&&>(hello); //same as move function
    string hello2 = move(hello); //converts hello to an rvalue. string has a move constructor "hello" string stolen and moved to hello2
    cout << "1: " << hello << endl;
    cout << "2: " << hello2 << endl;

    return 0;
}