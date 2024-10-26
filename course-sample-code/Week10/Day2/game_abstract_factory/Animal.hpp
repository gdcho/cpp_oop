//
// Created by A00257049 on 2020-11-06.
//

#ifndef GAME_ABSTRACT_FACTORY_ANIMAL_HPP
#define GAME_ABSTRACT_FACTORY_ANIMAL_HPP

#include <iostream>
using namespace std;

/*
    Animal defines the interface for one of the products that the
    abstract factory is responsible to create
 */
struct Animal {
    string name;
    int speed;

    Animal(string name, int speed) : name(name), speed(speed) {}
    void move() {
        cout << name << " moves " << speed << " squares " << endl;
    }
};

//Jellyfish is an animal that is generally found in the Aquatica World
struct Jellyfish : Animal {
    Jellyfish() : Animal("Jellyfish Critter" , 2) {}
};

//Firefly is an animal that is generally found in the Firelands world
struct Firefly : Animal {
    Firefly() : Animal("Firefly Critter" , 9) {}
};

#endif //GAME_ABSTRACT_FACTORY_ANIMAL_HPP
