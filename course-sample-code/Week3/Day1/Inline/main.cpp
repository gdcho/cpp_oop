#include <iostream>
//MACRO vs inline
#define SQUARE(x) ((x)*(x))

inline int square(int x) {return x*x;}

int main() {
    int n = 5;
    int n1 = 5;
    int value = SQUARE(n++); //(n++)*(n++) = 5*6 unexpected
    int value2 = square(n1++); //(n)*(n) = 5*5

    //std::cout << n << std::endl;
    std::cout << value << std::endl;
    //std::cout << n1 << std::endl;
    std::cout << value2 << std::endl;
    return 0;
}