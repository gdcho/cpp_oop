#include <iostream>
struct A
{
    virtual void foo(){}
    virtual ~A(){}
    int value;
    virtual void say() { std::cout << "I'm an A" << std::endl; }
};

struct B : public A
{
    virtual ~B() {} 
    float some_value;
    int foob() { return 22; }
    void say()  override { std::cout << "I'm a B" << std::endl; }

};

void f(A a) { a.say(); } // NOT POLYMORPHIC (SLICING)
void g(A& a) { a.say(); }
void h(A* a) { a->say(); }

int main()
{
	B b;
	f(b); // OK
	g(b); // OK
	h(&b); // OK

}