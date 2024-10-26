//
// Created by A00257049 on 2020-11-06.
//

#ifndef GAME_ABSTRACT_FACTORY_CHARACTERFACTORY_HPP
#define GAME_ABSTRACT_FACTORY_CHARACTERFACTORY_HPP
#include <iostream>
#include "Friendly.hpp"
#include "Enemy.hpp"
#include "Animal.hpp"

using namespace std;

/*
    The base factory class. All worlds expect this factory class to
    populate the world. The CharacterFactory class defines an interface
    to create the a Product family consisting of Friendlies, Enemies,
    and Animals. These vary by world.
 */
struct CharacterFactory {
    virtual Friendly* create_friendly() = 0;
    virtual Enemy* create_enemy() = 0;
    virtual Animal* create_animal() = 0;
};

/*
    This factory class implements the CharacterFactory Interface. It
    returns a product family consisting of MerPersons, Krakens, and
    Jellyfish.
 */
struct AquaticCharacterFactory : CharacterFactory {
    //return: returns a MerPerson
    Friendly* create_friendly() { return new MerPerson; }

    //return: Returns a Kraken
    Enemy* create_enemy() { return new Kraken;}

    //return: Returns a Jellyfish
    Animal* create_animal() { return new Jellyfish;}
};

/*
    This factory class implements the CharacterFactory Interface. It
    returns a product family consisting of FireSprites, Imps and
    Fireflies
 */
struct FirelandsCharacterFactory : CharacterFactory {
    //return: returns a FireSprite
    Friendly* create_friendly() { return new FireSprite; }

    //return: Returns a Imp
    Enemy* create_enemy() { return new Imp;}

    //return: Returns a Firefly
    Animal* create_animal() { return new Firefly;}
};

#endif //GAME_ABSTRACT_FACTORY_CHARACTERFACTORY_HPP
