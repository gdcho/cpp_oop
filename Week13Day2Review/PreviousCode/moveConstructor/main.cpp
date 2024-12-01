#include <iostream>

using namespace std;
class A {
public:
    string name;
    A(string &name) : name(name) {
        cout << "constructor" << endl;
    }

    A(string &&name) : name(move(name)) {
        cout << "move 'regular' constructor" << endl;
    }

    A(A &a) : name{a.name} {
        cout << "copy constructor" << endl;
    }

    A(A &&a) : name{move(a.name)} {
        cout << "move 'copy' constructor" << endl;
    }
};

int main() {
    string name = "Tracie";
    A a(move(name));
    A b(move(a));

    cout << endl;
    cout << "name" << name << endl;
    cout << "a name: " << a.name << endl;
    cout << "b name: " << b.name << endl;
    return 0;
}