#include <iostream>
#include "Character.hpp"

//this could be written in the header. This is to demonstrate it's a friend
//function implemented somewhere else
Character operator+(Character lhs, const Character &rhs) { //friend function
    lhs += rhs; //calls overloaded += that accepts a character
    return lhs;
}

int main() {
    Character char1('A');
    Character char2('B');
    cout << char1 << endl;
    cout << char2 << endl;

    //call addition operator in multiple ways
    cout << "Adding Character objects" << endl;
    char1 += char2; //adding with += operator
//    char1 = char1 + char2; //adding with + operator. Same as above
    cout << "char1: " << char1 << endl;

    return 0;
}