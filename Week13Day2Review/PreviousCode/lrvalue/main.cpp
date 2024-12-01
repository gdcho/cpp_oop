#include <iostream>
#include <queue>
using namespace std;

int globalX = 10;

int function() {return globalX;} //return by value so returns rvalue

int& functionRef(){return globalX;} //return by reference, so returns lvalue

int main() {
    cout << &function(); //function returns rvalue
    cout << &functionRef(); //functionref returns global x by reference, which is an lvalue
    const int constX = globalX; //constX is an lvalue
    cout << &constX << endl;

    int num = 10;
    int &&rvalurRef3 = 10;
    int &&rvalueRef = globalX; //can't assign lvalue to rvalue
    int &&rvalueRef2 = move(globalX); //can get rvalue ref using move
    cout << &rvalueRef2 << endl; //rvalueRef holds an rvalue, but rvalueRef itself is an lvalue!

    int y,z = 5;
    int && r = (y+z);
    cout << &(y+z) << endl; //result of expression (y+z) is an rvalue

    int x = 4;
    char c = 'c';

    cout << &"some string"; //strings are lvalues. Array of characters, arrays must exist in memory
    return 0;
}