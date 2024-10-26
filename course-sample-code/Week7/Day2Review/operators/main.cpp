#include <iostream>
#include "Character.hpp"

//this could be written in the header. This is to demonstrate it's a friend
//function implemented somewhere else
Character operator+(Character lhs, const Character &rhs) { //friend function
    lhs += rhs; //calls overloaded += that accepts a character
    return lhs;
}

Character operator+(Character lhs, const string val) { //friend function
    lhs += val; //calls overloaded += that accepts a string
    return lhs;
}

Character operator+(const string val, Character rhs) { //friend function
    return rhs + val; //reusing operator+ above that takes Character as left operand, and string as right operand
}

int main() {
    Character char1('A');
    cout << char1 << endl; //same as: operator<<(cout, char1) << endl; //Try this code without overloading << operator. Does it work?

    //call addition operator in multiple ways
    cout << "Adding Character object with a string on left and right operands" << endl;
    //char1 = char1 + 1; //ERROR without overloaded operator. Can't add int to my custom type
    char1 = char1 + "1"; //same as: char1 = operator+(char1,"1"); //operator+(Character lhs, const string val)
    char1 = "1" + char1; //same as: char1 = operator+("1", char1); //calls: operator+(const string val, Character rhs)

    cout << "After adding string to character object: " << char1 << endl;

    cout << "Adding two Character objects together" << endl;
    Character char2('B');
    Character char3('C');
    char2 = char2 + char3; //calls overloaded + operator accepting Character and Character
    cout << "After adding 2 character objects: " << char2 << endl;

    return 0;
}