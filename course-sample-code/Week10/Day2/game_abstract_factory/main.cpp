#include <iostream>
#include <vector>
#include "CharacterFactory.hpp"

/*
    Defines a world that consists of fFriendlies, Enemies and Animals.
    Each world has a theme/variety.
 */
struct World {
    vector<Friendly *> friendlies;
    vector<Enemy *> enemies;
    vector<Animal *> animals;
    CharacterFactory *char_factory;

    /*
        Instantiates a world with the specified character factory. The
        Character Factory specifies which type of characters inhabit
        this world.
        :param char_factory: a Character Factory
     */
    World(CharacterFactory *char_factory) : char_factory(char_factory) {
        for(int i=0; i<3; ++i)
            friendlies.push_back(char_factory->create_friendly());
        for(int i=0; i<3; ++i)
            enemies.push_back(char_factory->create_enemy());
        for(int i=0; i<3; ++i)
            animals.push_back(char_factory->create_animal());
    }

    /*
        Simulates behaviour of all the characters in this world.
        :return:
     */
    void simulate() {
        for(Friendly *f : friendlies){
            f->talk();
        }
        for(Enemy *e : enemies){
            cout << boolalpha << e->name <<
            " tried to defend! Success: " << e->defend() << endl;
        }
        for(Animal *a : animals){
            a->move();
        }
    }

    ~World() {
        for(Friendly *f : friendlies)
            delete f;
        for(Enemy *e : enemies)
            delete e;
        for(Animal *a : animals)
            delete a;
    }
};

int main() {
    srand (time(NULL));
    FirelandsCharacterFactory fireFactory;
    AquaticCharacterFactory aquaticFactory;

    World world(&fireFactory); //create fire populated world
    //World world(&aquaticFactory); //create aquatic populated world

    world.simulate();

    return 0;
}