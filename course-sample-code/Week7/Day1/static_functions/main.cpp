#include <iostream>
using namespace std;

class A {
    string nonStaticName = "My name is class A";
    static int staticNum;

public:
    static void staticFunction1() {
        cout << "staticFunction1" << endl;

        //nonStaticFunction(); //ERROR: can't call non static without instance
        //cout << nonStaticName << endl; //ERROR: can't call non static data members in static function
        cout << "Printing static number: " << staticNum << endl; //CAN call static data members in static function
        staticFunction2(); //CAN call other static functions in static function
    }

    static void staticFunction2() {
        cout << "staticFunction2" << endl;
    }

    static void staticFunctionParam(A a) {
        cout << "staticFunctionParam" << endl;
        //nonStaticFunction(); //CAN'T call non-static function directly
        a.nonStaticFunction(); //CAN call non-static function through parameter a
    }

    void nonStaticFunction() {
        cout << "nonStaticFunction" << endl;
        cout << "Printing non static name: " << this->nonStaticName << endl; //CAN access non-static data member in non-static function
        //staticFunction2(); //CAN call static function in non-static function
    }
};

int A::staticNum = 5; //initialize static variable outside class

int main() {
    cout << "---Calling static function that calls another static function---" << endl;
    A::staticFunction1();
    cout << endl;

    cout << "---Calling static function that accepts a parameter to call a non static function---" << endl;
    A aInstance;
    A::staticFunctionParam(aInstance);

    return 0;
}
