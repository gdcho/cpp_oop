//
// Created by David Cho on 2024-11-11.
//

#ifndef DOOR_HPP
#define DOOR_HPP

#include "maze_object.hpp"
#include <iostream>

/* forward declaration of room class */
class Room;

/**
 * @class Door
 * @brief represent a door in the maze
 * @details the Door class is a subclass of Maze_Object
 * and is used to represent a door in the maze
 */
class Door : public Maze_Object {
private:
    /* the two room pointers that the door connects */
    Room *room1 = nullptr;
    Room *room2 = nullptr;

public:
    /**
     * @brief constructor for the Door class
     */
    Door() = default;

    /**
     * @brief destructor for the Door class
     */
    virtual ~Door() = default;

    /**
     * @brief sets the first room connected by this door
     * @param room pointer to the first Room object
     */
    virtual void addRoom1(Room *room) {
       this->room1 = room;
    }

    /**
     * @brief sets the second room connected by this door
     * @param room pointer to the second Room object
     */
    virtual void addRoom2(Room *room) {
       this->room2 = room;
    }

    /**
     * @brief prints the description of the door
     * @return pointer to the first Room object
     */
    Room* getRoom1() const { return room1; }

    /**
     * @brief prints the description of the door
     * @return pointer to the second Room object
     */
    Room* getRoom2() const { return room2; }
};

/**
 * @class Fairy_Door
 * @brief represent a fairy door in the maze
 * @details the Fairy_Door class is a subclass of Door
 * and is used to represent a fairy door in the maze
 */
class Fairy_Door : public Door {
public:

    /**
     * @brief constructor for the Fairy_Door class
     */
    Fairy_Door() : Door() {}

    /**
     * @brief prints the description of the fairy door
     */
    void print_description() override;
};

/**
 * @class Dystopian_Door
 * @brief represent a dystopian door in the maze
 * @details the Dystopian_Door class is a subclass of Door
 * and is used to represent a dystopian door in the maze
 */
class Dystopian_Door : public Door {
public:
    /**
     * @brief constructor for the Dystopian_Door class
     */
    Dystopian_Door() : Door() {}

    /**
     * @brief prints the description of the dystopian door
     */
    void print_description() override;
};

#endif //DOOR_HPP
