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
    Character(char c) : c(c){cout << "constructing char: " << c << endl;}

    Character(const Character& other) : c(other.c) {}

    ~Character() {}

    Character& operator=(Character rhs) {
        mySwap(*this, rhs);
        return *this;
    }

    void mySwap(Character &original, Character &other) {
        std::swap(original.c, other.c);
    }

    Character& operator++() {
        c += 1;
        return *this;
    }

    Character operator++(int){
        Character tmp(*this);
        operator++();
        return tmp;
    }

    Character& operator+=(const Character& rhs) {
        c += rhs.c;
        return *this;
    }

private:
    friend Character operator+(Character lhs, const Character &rhs);

    friend bool operator== (const Character &lhs, const Character &rhs) {
        return lhs.c == rhs.c;
    }

    friend bool operator!= (const Character &lhs, const Character &rhs) {
        //return !(lhs == rhs);
        return !operator==(lhs,rhs);
    }

    friend bool operator< (const Character &lhs, const Character &rhs) {
        return lhs.c < rhs.c;
    }

    friend bool operator> (const Character &lhs, const Character &rhs) {
        //return rhs < lhs;
        return operator<(rhs,lhs);
    }

    friend bool operator<= (const Character &lhs, const Character &rhs) {
        //return !(lhs > rhs);
        return !operator>(lhs, rhs);
    }

    friend bool operator>= (const Character &lhs, const Character &rhs) {
        //return !(lhs < rhs);
        return !operator<(lhs,rhs);
    }

    friend ostream& operator<<(ostream &os, const Character& character) {
        os << "Character: " << character.c << endl;
        return os;
    }
};
#endif //OPERATORS_CHARACTER_HPP
