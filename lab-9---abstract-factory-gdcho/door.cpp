//
// Created by David Cho on 2024-11-11.
//

#include "door.hpp"
#include "room.hpp"

/**
 * Print the description of the fairy door
 * @return void
 */
void Fairy_Door::print_description() {
    std::cout << "This door has a fairy wing for a handle." << std::endl
              << "This door connects fairy Room " << getRoom1()->get_id()
              << " and fairy Room " << getRoom2()->get_id() << std::endl;
}

/**
 * Print the description of the dystopian door
 * @return void
 */
void Dystopian_Door::print_description() {
    std::cout << "This door has a fingerprint scanner for a handle." << std::endl
              << "This door connects dystopian Room " << getRoom1()->get_id()
              << " and dystopian Room " << getRoom2()->get_id() << std::endl;
}
