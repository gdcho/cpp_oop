//
// Created by David Cho on 2024-09-23.
//

#include "animal.hpp"

// Static variable
long Animal::idCounter = 0;

// Constructors
Animal::Animal() : age(0), id(idCounter++), alive(true),  x(0.0), y(0.0), z(0.0) {
    std::cout << "animal constructor" << std::endl;
}

Animal::Animal(int age, double x, double y, double z) : age(age), alive(true), x(x), y(y), z(z) {
    id = idCounter++;
    std::cout << "animal constructor" << std::endl;
}

// Copy Constructor
Animal::Animal(const Animal& other)
    : age(other.age), alive(other.alive), x(other.x), y(other.y), z(other.z) {
    id = idCounter++;
    std::cout << "animal copy constructor" << std::endl;
}

// Destructor
Animal::~Animal() {
    std::cout << "animal destructor" << std::endl;
}

// move function
void Animal::move(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
    std::cout << "Animal " << id << " moved to (" << x << ", " << y << ", " << z << ")\n";
}

// sleep function
void Animal::sleep() {
    std::cout << "Animal is sleeping" << std::endl;
}

// eat function
void Animal::eat() {
    std::cout << "Animal is eating something" << std::endl;
}

// setAlive function
void Animal::setAlive(bool aliveStatus) {
    alive = aliveStatus;
}

// getId function
long Animal::getId() const {
    return id;
}

// getX function
double Animal::getX() const {
    return x;
}

// getY function
double Animal::getY() const {
    return y;
}

// getZ function
double Animal::getZ() const {
    return z;
}

// print function
void Animal::print(std::ostream& out) const {
    out << "animal:[age=" << age
        << ", id=" << id
        << ", alive=" << alive
        << ", location=(" << x << ", " << y << ", " << z << ")]";
}

// operator<< function
std::ostream& operator<<(std::ostream& out, const Animal& animal) {
    animal.print(out);
    return out;
}