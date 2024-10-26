//
// Created by David Cho on 2024-09-23.
//

#include "bird.hpp"

// Constructors
Bird::Bird() : Animal() {
    std::cout << "bird constructor" << std::endl;
}

Bird::Bird(int age, double x, double y, double z) : Animal(age, x, y, z) {
    std::cout << "bird constructor" << std::endl;
}

// Copy Constructors
Bird::Bird(const Bird& other) : Animal(other) {
    std::cout << "bird copy constructor" << std::endl;
}

// Destructor
Bird::~Bird() {
    std::cout << "bird destructor" << std::endl;
}

// move function
void Bird::move(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
    std::cout << "Bird " << id << " moved to (" << x << ", " << y << ", " << z << ")\n";
}

// sleep function
void Bird::sleep() {
    std::cout << "Bird is sleeping" << std::endl;
}

// eat function
void Bird::eat() {
    std::cout << "Bird is eating a worm" << std::endl;
}

// print function
void Bird::print(std::ostream& out) const {
    out << "bird:[age=" << age
        << ", id=" << id
        << ", alive=" << alive
        << ", location=(" << x << ","
        << y << ","
        << z << ")]";
}

// operator<< function
std::ostream& operator<<(std::ostream& out, const Bird& bird) {
    bird.print(out);
    return out;
}

