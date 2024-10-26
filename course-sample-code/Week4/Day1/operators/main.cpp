#include <iostream>
#include "Character.hpp"

Character operator+(Character lhs, const Character &rhs) {
    lhs += rhs;
    return lhs;
}

int main() {
    Character char1('!');
    Character char2('#');

    cout << boolalpha;
    cout << "char1 less than char2? " << (char1 < char2) << endl;

    cout << char1;
    cout << char2;

    //cout << "adding to char1" << endl << endl;
    //char1++;
    //Character b = '!';

    //Two ways to write += operator
    //char1 += b;
    //char1.operator+=(b);

    //Two ways to write + operator
    //char1 = char1 + b;
    //char1 = operator+(char1,b);

    cout << "After changes" << endl;
    cout << char1;
    cout << char2;

    cout << "copy assign char1 to char2" << endl << endl;
    char2 = char1;

    cout << char1;
    cout << char2;

    return 0;
}