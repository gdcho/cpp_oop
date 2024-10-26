#include <iostream>
#include "Calculator.hpp"

using namespace std;

void function() {
    Calculator c; //need to instantiate Calculator to use it
    int x = 100;
    int y = 50;
    cout << c.add(x,y) << endl;
    cout << c.subtract(x,y) << endl;
}

int main() {
    Calculator c; //need to instantiate Calculator to use it
    int x = 10;
    int y = 5;
    cout << c.add(x,y) << endl;
    cout << c.subtract(x,y) << endl;

    function();
    return 0;
}