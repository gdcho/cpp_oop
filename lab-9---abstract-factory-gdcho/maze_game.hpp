//
// Created by David Cho on 2024-11-11.
//

#ifndef MAZE_GAME_HPP
#define MAZE_GAME_HPP

#include "maze_factory.hpp"

/**
 * @class Maze_Game
 * @brief represent a maze game
 * @details the Maze_Game class is used to create a maze
 */
class Maze_Game {
public:
    /**
     * @brief creates a new maze
     * @param factory pointer to the Maze_Factory object
     * @return pointer to the Maze object
     */
    Maze *create_maze(Maze_Factory *factory) {
        /* create a new maze */
        Maze *maze = factory->make_maze();

        /* create two rooms */
        Room *room1 = factory->make_room(0);
        Room *room2 = factory->make_room(1);
        /* create a door */
        Door *door = factory->make_door(room1, room2);

        /* add walls to the rooms */
        for (int i = 0; i < 4; i++) {
            room1->add_wall(factory->make_wall());
            room2->add_wall(factory->make_wall());
        }

        /* add the rooms to the maze */
        maze->add_room(room1);
        maze->add_room(room2);
        /* add the door to the maze */
        maze->add_door(door);

        /* print the description of the maze */
        maze->print_description();
        /* print the description of the door */
        door->print_description();
        std::cout << "Room 1: ";
        /* print the description of the room 1 */
        room1->print_description();
        std::cout << "Room 2: ";
        /* print the description of the room 2 */
        room2->print_description();

        /* return the maze */
        return maze;
    }
};

#endif //MAZE_GAME_HPP
