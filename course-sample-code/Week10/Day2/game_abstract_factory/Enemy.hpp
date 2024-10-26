//
// Created by A00257049 on 2020-11-06.
//

#ifndef GAME_ABSTRACT_FACTORY_ENEMY_HPP
#define GAME_ABSTRACT_FACTORY_ENEMY_HPP
#include <iostream>
using namespace std;

/*
    Enemy defines the interface for one of the products that the
    abstract factory pattern is responsible to create.
 */
struct Enemy {
    string name;
    int health;
    int strength;
    int dodge_chance;

    Enemy(string name, int health, int strength, int dodge_chance)
    : name(name), health(health), strength(strength), dodge_chance(dodge_chance) {}

    void attack() {
        cout << name << "attacks your ship." << endl;
    }

    bool defend() {
        return (rand() % 100 + 1) < dodge_chance;
    }
};

//Kraken is an enemy generally found in the Aquatica World
struct Kraken : Enemy {
    Kraken() : Enemy("Mr.Kraken", 90, 100, 30) {}
};

//Imp is an enemy generally found in the Firelands World.
struct Imp : Enemy {
    Imp() : Enemy("Imp minion", 20, 20, 50) {}
};

#endif //GAME_ABSTRACT_FACTORY_ENEMY_HPP
