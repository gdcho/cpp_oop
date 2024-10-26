//
// Created by A00257049 on 2020-10-14.
//

#include "MyClass.hpp"
#include <iostream>
using namespace std;

MyClass::MyClass(int x, int y) {
    this->x = 5;
    this->y = 10;
}

void MyClass::complicatedFunction() {
    cout << x << endl;
    cout << y << endl;
}