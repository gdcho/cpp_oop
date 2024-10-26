#include <iostream>

class Base
{
public:
   virtual void f() { std::cout << "base\n"; }
};

class Derived : public Base
{
public:
    void f() override { std::cout << "derived\n"; }
};

int main()
{
    Base b;
    Derived d;
 
    // virtual function call through reference
    Base& br = b; // the type of br is Base&
    Base& dr = d; // the type of dr is Base& as  well
    br.f(); // prints "base"
    dr.f(); // prints "derived"

    std::cout << std::endl;

    // virtual function call through pointer
    Base* bp = &b; // the type of bp is Base*
    Base* dp = &d; // the type of dp is Base* as  well
    bp->f(); // prints "base"
    dp->f(); // prints "derived"

    std::cout << std::endl;

    // non-virtual function call
    br.Base::f(); // prints "base"
    dr.Base::f(); // prints "base"

    std::cout << std::endl;

    Base baseDerived = d; //d is a derived type
    baseDerived.f(); //prints what? base? or derived? // base
}