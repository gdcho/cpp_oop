//
// Created by David Cho on 2024-11-11.
//

#ifndef MAZE_HPP
#define MAZE_HPP

#include <vector>
#include "room.hpp"
#include "door.hpp"

using namespace std;

/**
 * @class Maze
 * @brief represent a maze
 * @details the Maze class is a subclass of Maze_Object
 * and is used to represent a maze
 */
class Maze : public Maze_Object {
private:
    /* vector of room pointers */
    vector<Room *> rooms;
    /* vector of door pointers */
    vector<Door *> doors;

public:
    /**
     * @brief constructor for the Maze class
     */
    Maze() = default;

    /**
     * @brief adds a room to the maze
     * @param room pointer to the Room object
     * @return void
     */
    void add_room(Room *room) {
        this->rooms.push_back(room);
    }

    /**
     * @brief adds a door to the maze
     * @param door pointer to the Door object
     * @return void
     */
    void add_door(Door *door) {
        this->doors.push_back(door);
    }

    /**
     * @brief prints the description of the maze
     */
    virtual ~Maze() {
        for (auto room: this->rooms) {
            delete room;
        }
        for (auto door: this->doors) {
            delete door;
        }
    }
};

/**
 * @class Fairy_Maze
 * @brief represent a fairy maze
 * @details the Fairy_Maze class is a subclass of Maze
 * and is used to represent a fairy maze
 */
class Fairy_Maze : public Maze {
public:
    /**
     * @brief constructor for the Fairy_Maze class
     */
    Fairy_Maze() = default;

    /**
     * @brief prints the description of the fairy maze
     * @return void
     */
    void print_description() override {
        cout << "A pretty, magical fairy maze" << endl;
    }
};

/**
 * @class Dystopian_Maze
 * @brief represent a dystopian maze
 * @details the Dystopian_Maze class is a subclass of Maze
 * and is used to represent a dystopian maze
 */
class Dystopian_Maze : public Maze {
public:
    /**
     * @brief constructor for the Dystopian_Maze class
     */
    Dystopian_Maze() = default;

    /**
     * @brief prints the description of the dystopian maze
     * @return void
     */
    void print_description() override {
        cout << "An Orwellian dystopian maze" << endl;
    }
};

#endif //MAZE_HPP
