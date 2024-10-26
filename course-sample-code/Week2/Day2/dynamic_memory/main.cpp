#include <iostream>
using namespace std;
/*
 * This sample code illustrates a scenario to use dynamic memory.
 * Dynamic memory should be used when we allocate an object in one scope, to use in another scope
 * It's also used to create more efficient code that reduces the number of copies that are made
 */

//simulating a resource intensive class
class MyClass {
public:
    int myInt;
    double myDouble;
    string myString;
    void print() { cout << "MyClass printout" << endl;}
};

MyClass * instantiateDynamicMyClass() {
    MyClass *mcDynamic = new MyClass(); //create resource intensive class with dynamic memory onto HEAP memory
    mcDynamic->print(); //call print function. -> replaces . syntax when using pointers
    return mcDynamic; //efficient return statement COPIES resource light mcDynamic pointer
}

MyClass instantiateMyClass() {
    MyClass mc; //create resource intensive class with non-dynamic (static) memory onto STACK memory
    mc.print(); //call print function
    return mc; //inefficient return statement COPIES resource intensive mc object
}

int main() {
    MyClass mc = instantiateMyClass(); //mc gets a COPY of MyClass - resource intensive

    MyClass *mcPtr = instantiateDynamicMyClass(); //mcPtr gets a COPY of MyClass pointer - resource light
    delete mcPtr; //delete mcPtr to delete original MyClass() object created in instantiateDynamicMyClass function
}
