#include <iostream>
using namespace std;
int main() {
    int a = 2;
    int b = 2;
    int c = 2;
    int d = 2;
    int e = 2;

    a >>= 1; //equal to a = a >> 1;
    b <<= 1; //equal to b = b << 1;
    c &= 1; //equal to c = c & 1;
    d |= 1; //equal to d = d | 1;
    e ^= 1; //equal to e = e ^ 1;

    cout << endl;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;

    return 0;
}