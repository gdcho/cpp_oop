#include <iostream>
#include "MyClass.hpp"

void friendFunc(MyClass1 mc)
{
    mc.x++;
    std::cout << "mc.x: " << mc.x << std::endl;
}

int main() {
    MyClass mc(100,200);
    mc.complicatedFunction();

    MyClass1 mc1;
    friendFunc(mc1);
    return 0;
}