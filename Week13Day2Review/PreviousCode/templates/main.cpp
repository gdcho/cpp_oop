#include <iostream>

using namespace std;

template <typename T=int>
class A {
    T t;
public:
    A(T t) : t(t) {}
    void print() {cout << t << endl;}
};

template <typename T>
void myPrint1(T t, T t2) {
    cout << t << " " << t2 << endl;
}

template <typename T, typename T2>
void myPrint2(T t, T2 t2) {
    cout << t << " " << t2 << endl;
}

template <typename T, typename T2>
void myPrint2(T t, T2 t2, T2 t3) {
    cout << t << " " << t2 << " " << t3 << endl;
}

int main() {

    //A a(5); //C++ 17 - Allows class to deduce template type from constructor
    A<> a(5); //can have empty template arguments if template parameters have default type ie: int

    //myPrint1(5, 5.0); //cannot infer type because function has only 1 template argument
    myPrint1<int>(5, 5.0); //explicitly telling template to accept both parameters as int

    cout << endl;
    myPrint2('a', 'b'); //infer template variables T and T2 to char
    myPrint2(10, 'b'); //infer T to int, T2 to char
    myPrint2<int, char>(5, 65); //explicitly telling T is int, T2 is char

    cout << endl;
    myPrint2(10, 'b', 'b'); //OK
    //myPrint2(10, 'b', 10); //ERROR
    //myPrint2(10, 10, 'b'); //ERROR
    //myPrint2(10, 'b', "hello"); //ERROR

    return 0;
}