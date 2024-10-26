//
// Created by David Cho on 2024-09-23.
//

#include "canine.hpp"
#include "bird.hpp"
#include <cmath>

// Constructors
Canine::Canine() : Animal() {
    std::cout << "canine constructor" << std::endl;
}

Canine::Canine(int age, double x, double y) : Animal(age, x, y, 0.0) {
    std::cout << "canine constructor" << std::endl;
}

// Copy Constructor
Canine::Canine(const Canine& other) : Animal(other) {
    std::cout << "canine copy constructor" << std::endl;
}

// Destructor
Canine::~Canine() {
    std::cout << "canine destructor" << std::endl;
}

// move function
void Canine::move(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
    std::cout << "Canine " << id << " moved to (" << x << ", " << y << ", " << z << ")\n";
}

// sleep function
void Canine::sleep() {
    std::cout << "Canine is sleeping" << std::endl;
}

// eat function
void Canine::eat() {
    std::cout << "Canine is eating grass" << std::endl;
}

// hunt function
void Canine::hunt(Animal* animal) {
    double dx = std::abs(x - animal->getX());
    double dy = std::abs(y - animal->getY());
    double dz = std::abs(z - animal->getZ());

    if (dx <= 1.0 && dy <= 1.0 && dz <= 1.0) {
        animal->setAlive(false);
        std::string huntedAnimal = "animal";
        if (dynamic_cast<Bird*>(animal)) {
            huntedAnimal = "bird";
        } else if (dynamic_cast<Canine*>(animal)) {
            huntedAnimal = "canine";
        }
        std::cout << "Canine " << id << " successfully hunted " << huntedAnimal << std::endl;
    } else {
        std::cout << "Canine " << id << " failed to hunt prey" << std::endl;
    }
}

// print function
void Canine::print(std::ostream& out) const {
    out << "canine:[age=" << age
        << ", id=" << id
        << ", alive=" << alive
        << ", location=(" << x << ","
        << y << ","
        << z << ")]";
}

// operator<< function
std::ostream& operator<<(std::ostream& out, const Canine& canine) {
    canine.print(out);
    return out;
}