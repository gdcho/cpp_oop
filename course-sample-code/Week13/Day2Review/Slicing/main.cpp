#include <iostream>
using namespace std;

class Parent {
public:
    Parent() = default;
    Parent(const Parent& p)
    {
        cout << "Parent copying" << endl;
    }
    virtual void speak() {
        cout << "Parent speaking" << endl;
    }
    virtual ~Parent() {}
};

class Child : public Parent {
public:
    Child() = default;
    Child(const Child& p)
    {
        cout << "Child copying" << endl;
    }
    void speak() {
        cout << "Child speaking" << endl;
    }
    ~Child() {
        cout << "Child destroyed" << endl;
    }
};

//return slicing
Parent createChild() {
    return Child{};
}

//parameter slicing
void someoneSpeak(Parent p)
{
    p.speak();
}

//return slicing fixed
Parent* createChildFixed() {
    return new Child{};
}

//parameter slicing fixed
void someoneSpeakFixed(Parent* p)
{
    p->speak();
}

int main() {
    //calling slicing functions
    Child c;
    someoneSpeak(c); //expecting child speaking to be printed out

    Parent p = createChild();
    p.speak(); //expecting child speaking to be printed out


//    //calling fixed slicing functions
//    Child *cPtr = new Child;
//    someoneSpeakFixed(cPtr);
//
//    Parent *pPtr = createChildFixed();
//    pPtr->speak();
//
//    delete cPtr;
//    delete pPtr;

    return 0;
}