#include <iostream>
#include <vector>
using namespace std;

//Deleting Dynamic Memory best practices. Destructors

//If there's a "new" must have a corresponding "delete" somewhere else
//Ownership - Who owns that dynamic memory? Owner's responsibility to destroy memory
//Scope - When is the last place a pointer to dynamic memory exists before going out of scope?

class OtherClass {
public:
    ~OtherClass() {
        cout << "OtherClass destructor" << endl;
    }
};

class MyClass {
public:
    //ptr owned by MyClass. MyClass' responsibility to destroy it in destructor
    //OtherClass *ptr should be private. It's made public to show bad practice of
    //allowing code outside MyClass to delete the pointer
    OtherClass* ptr;

    MyClass() {
        ptr = new OtherClass;
    }

    ~MyClass() {
        delete ptr;
        cout << "MyClass destructor" << endl;
    }
};

MyClass* create_my_class() {
    return new MyClass;
}

void operate(MyClass* mc) {
    cout << "operate on mc" << endl;
}

int main() {

    MyClass* mc = create_my_class();
    delete mc;

    {//curly braces indicate an inner scope. Simulates calling a function
        MyClass* mc2 = create_my_class();
        //memory leak for mc2, need to delete before leaving inner scope
    }

    //MyClass* mc3 = create_my_class();

    //deleting mc3-> ptr in main is BAD.
    //MyClass owns ptr. MyClass should delete ptr in its destructor
    //code in main should not be responsible for deleting data member in MyClass
    //delete mc3->ptr;

    //delete mc;

    return 0;
}