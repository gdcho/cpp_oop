#include <iostream>
using namespace std;

class Class1 {
public:
    void doSomething() {
        cout << "class 1 doing something" << endl;
    }
};

class Class2 {
public:
    void doSomething() {
        cout << "class 2 doing something" << endl;
    }
};

class Class3 {
public:
    void doSomething() {
        cout << "class 3 doing something" << endl;
    }
};

/*
 *  This class contains all the classes that perform complicated code
    It provides a simple interface for the client to access in order to
    begin the action of the complicated code
 */
class Facade {
private:
    Class1 c1;
    Class2 c2;
    Class3 c3;

public:
    void execute1() {
        c1.doSomething();
        c2.doSomething();
        c3.doSomething();
    }

    void execute2() {
        c3.doSomething();
        c1.doSomething();
        c2.doSomething();
        c3.doSomething();
        c1.doSomething();
        c1.doSomething();
    }
};

int main() {
    //instantiate the facade
    Facade f;

    //the client only interacts with the facade, not the classes within
    //f.execute1();
    f.execute2();
    
    return 0;
}