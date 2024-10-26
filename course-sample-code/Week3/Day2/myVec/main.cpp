#include <iostream>
#include "MyVec.hpp"

using namespace std;
int main() {
    double vArray[] = {3,6,7};
    MyVec v;
    v.size = 3;
    v.data = vArray;
    MyVec vCopy = v;

    for (int i = 0; i < 3; ++i) {
        cout << "data: " << v.data[i] << " address: " << &v.data[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < 3; ++i) {
        cout << "data: " << vCopy.data[i] << " address: " << &vCopy.data[i] << endl;
    }
    return 0;
}