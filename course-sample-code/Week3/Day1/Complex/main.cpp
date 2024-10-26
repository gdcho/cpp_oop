#include <iostream>
//Order of initialization depends on declaration, not order of member initialization
using namespace std;

class A {
public:
    A(){};
    A(const A &a){cout << "A copy constructed\n";};
};

class B {
public:
    B(){};
    B(const B &b){cout << "B copy constructed\n";};
};

class complex
{
private:
    int r, i;
    A a;
    B b;
public:
    complex(const A &a, const B &b, int r = 0, int i = 0) : a(a), b(b), r(r), i(i)
    {
        cout << "constructor of complex" << endl;
    }
    int get_r() { return r; }
    int get_i() { return i; }
};

int main()
{
    A a;
    B b;
    complex c{a,b,5,0,};
    cout << c.get_r() << " " << c.get_i() << endl;
}