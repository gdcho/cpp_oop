#include <iostream>

int main() {
    //ternary
    int x = 0;
    bool lessThanNum = false;
    std::cout << "Enter a number" << std::endl;
    std::cin >> x;
    if(x < 5)
    {
        lessThanNum = true;
    }
    else
    {
        lessThanNum = false;
    }
    //lessThanNum = x < 5 ? true : false;
    std::cout << x << " is less than 5: " << std::boolalpha << lessThanNum  << std::endl;

    //comma operator
    int n = 1;
    int m = (++n, std::cout << "n = " << n << '\n', ++n, 2*n);
    std::cout << "m = " << (++m, m) << '\n';

    //casting operator
    int anInt = 0;
    float aFloat = (float)anInt;

    return 0;
}
