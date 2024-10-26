#include <iostream>
using namespace std;

struct MyNum {
    int num;
    MyNum(int n) : num(n) { cout << "Construct MyNum" << endl; }

    ~MyNum() { cout << "Destructor MyNum" << endl; }
};

struct MyClass {
    MyNum *numPtr;

    MyClass() {
        numPtr = new MyNum{10};
        cout << "Construct MyClass" << endl;
    }

    ~MyClass(){
        delete numPtr;
        cout << "Destructor MyClass" << endl;
    }
};

int main() {
    MyClass *mcPtr = new MyClass;
    delete mcPtr;

    MyClass mc;

    return 0;
}