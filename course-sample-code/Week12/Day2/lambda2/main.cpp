#include <iostream>

using namespace std;

struct myFunctor {
    int x;
    myFunctor(int x) : x(x) {}
    int operator()(int y) {
        x += y;
        return x;
    }
};

int main() {
    int x = 0;

    myFunctor f(x);
    cout << "---myFunctor:---\n";
    cout << f(5) << endl;
    cout << f(10) << endl << endl;

    //x in lambda acts as member variable, saves state
    auto myLambda = [x] (int y) mutable {x += y; return x;}; //gets copy of x and doesn't modify x outside
    //auto myLambda = [&x] (int y) {x += y; return x;}; //modifies x outside

    cout << "---myLambda:---\n";
    cout << "value x in lambda: " << myLambda(5) << endl;
    cout << "value x in lambda: " << myLambda(10) << endl << endl;

    cout << "final outside x value: " << x << endl;
    return 0;
}