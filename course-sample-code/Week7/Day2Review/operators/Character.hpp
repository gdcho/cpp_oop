//
// Created by A00257049 on 2019-01-28.
//

#ifndef OPERATORS_CHARACTER_HPP
#define OPERATORS_CHARACTER_HPP

#include <iostream>

using namespace std;
class Character {
    char c;

public:
    Character() {c = ' ';}
    explicit Character(char c) : c(c){cout << "constructing char: " << c << endl;}
    Character(const Character& other) = default;
    ~Character() = default;

    //Can the same operator (+=) be overloaded more than once?
    //YES, just need a different number or type of parameter. Here the parameter is
    //of type Character
    Character& operator+=(const Character& rhs) {
        c += rhs.c;
        return *this;
    }

private:
    //Overloading the + operator
    friend Character operator+(Character lhs, const Character &rhs);

    friend ostream& operator<<(ostream &os, const Character& character) {
        os << "Character: " << character.c << endl;
        return os;
    }
};
#endif //OPERATORS_CHARACTER_HPP
