#include <iostream>

struct A { ~A(){}};
struct B : A {};

struct C { virtual ~C(){}};
struct D : C {};

int main() {
    A *a = new A;
    //B *b = dynamic_cast<B*>(a); //a is not polymorphic
    B *b = static_cast<B*>(a); //use static cast, non polymorphic

    C *c = new C;
    D *d = dynamic_cast<D*>(c); //c is polymorphic - see virtual ~C
    D *d2 = static_cast<D*>(c); //can also use static cast
    return 0;
}