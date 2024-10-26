#include <iostream>

using namespace std;
class Object {
public:
    Object() {cout << "construct" << endl;}
    Object(const Object &o) {cout << "copy" << endl;}
    Object(const Object &&o) {cout << "copy 2" << endl;}
    ~Object() {cout << "destroy" << endl;}
};

Object createObject() {
    Object o;
    return o;
}

int main() {
    Object o = createObject();
    return 0;
}