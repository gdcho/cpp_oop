#include <iostream>
#include "Dollar.hpp"
#include "Random.hpp"
//this implementation can be anywhere. Does NOT belong to Dollar class
Dollar sum(const Dollar &d1, const Dollar &d2)
{
    return Dollar(d1.num + d2.num);
}

int main() {
    Dollar d1{5};
    Dollar d2{7};

    Dollar dollarSum = sum(d1,d2);
    std::cout << dollarSum.GetNum() << std::endl;
    return 0;
}




