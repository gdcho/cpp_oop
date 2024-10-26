//
// Created by A00257049 on 2020-11-06.
//

#ifndef GAME_ABSTRACT_FACTORY_FRIENDLY_HPP
#define GAME_ABSTRACT_FACTORY_FRIENDLY_HPP

#include <iostream>
using namespace std;

/*
    Friendly defines the interface for one of the products that the
    abstract factory pattern is responsible to create.
 */
struct Friendly {
    string name;
    int health;

    Friendly(string name, int health) : name(name), health(health) {}
    virtual void talk() = 0;
};

//MerPerson is a type of Friendly usually found in the Aquatica World.
struct MerPerson : Friendly {
    MerPerson() : Friendly("MerPerson", 50) {}
    void talk() override {cout << "Hi, I'm a MerPerson" << endl;}
};

//    FireSprite is a type of Friendly usually found in the Firelands World.
struct FireSprite : Friendly {
    FireSprite() : Friendly("FireSprite", 100) {}
    void talk() override {cout << "Hi, I'm a FireSprite" << endl;}
};

#endif //GAME_ABSTRACT_FACTORY_FRIENDLY_HPP
