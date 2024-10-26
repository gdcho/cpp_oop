//
// Name: David Cho
// Student# : A01351217
// Created by David Cho on 2024-09-23.
//

#include "animal.hpp"
#include "bird.hpp"
#include "canine.hpp"

int main() {
    // Create all animals
    std::cout << "---Create all animals---" << std::endl;
    Animal* animalPtr = new Animal(10, 2, 8);
    Animal* birdPtr = new Bird(15, 6, 3, 7);
    Animal* caninePtr = new Canine(15, 8, 1);

    // Print all animals
    std::cout << "\n---Print all animals---" << std::endl;
    std::cout << *animalPtr << std::endl;
    std::cout << *dynamic_cast<Bird*>(birdPtr) << std::endl;
    std::cout << *dynamic_cast<Canine*>(caninePtr) << std::endl;

    // Make all animals move and print
    std::cout << "\n---Make all animals move and print---" << std::endl;
    animalPtr->move(1, 1);
    birdPtr->move(1, 2, 0);
    caninePtr->move(1, 2);

    // Print all animals
    std::cout << *animalPtr << std::endl;
    std::cout << *birdPtr << std::endl;
    std::cout << *caninePtr << std::endl;

    // Make all animals sleep
    std::cout << "\n---Make all animals sleep---" << std::endl;
    animalPtr->sleep();
    birdPtr->sleep();
    caninePtr->sleep();

    // Make all animals eat
    std::cout << "\n---Make all animals eat---" << std::endl;
    animalPtr->eat();
    birdPtr->eat();
    caninePtr->eat();

    // Make canine hunt bird
    std::cout << "\n---Make canine hunt bird---" << std::endl;
    if (Canine* canine = dynamic_cast<Canine*>(caninePtr)) {
        canine->hunt(birdPtr);
    }

    // Print all animals
    std::cout << "\n---Print all animals at end---" << std::endl;
    std::cout << *animalPtr << std::endl;
    std::cout << *birdPtr << std::endl;
    std::cout << *caninePtr << std::endl;

    // Delete dynamic memory
    std::cout << "\n---Delete dynamic memory---" << std::endl;
    delete animalPtr;
    delete birdPtr;
    delete caninePtr;

    return 0;
}
