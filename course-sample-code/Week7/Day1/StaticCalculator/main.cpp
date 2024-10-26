#include <iostream>
#include "Calculator.hpp"

using namespace std;

void function() {
    int x = 100;
    int y = 50;
    cout << Calculator::add(x,y) << endl; //no need to instantiate calculator
    cout << Calculator::subtract(x,y) << endl;
}

int main() {
    int x = 10;
    int y = 5;
    cout << Calculator::add(x,y) << endl; //no need to instantiate calculator
    cout << Calculator::subtract(x,y) << endl;

    function();
    return 0;
}