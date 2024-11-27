//
// Created by David Cho on 2024-11-11.
//

// room.hpp
#ifndef ROOM_HPP
#define ROOM_HPP

#include "wall.hpp"
#include "maze_object.hpp"
#include <vector>

/* forward declaration of door class */
class Door;

/**
 * @class Room
 * @brief represent a room in the maze
 * @details the Room class is a subclass of Maze_Object
 * and is used to represent a room in the maze
 */
class Room : public Maze_Object {
protected:
    /* vector of wall pointers */
    std::vector<Wall *> walls;
    /* pointer to the door object */
    Door *door = nullptr;
    /* the id of the room */
    int room_id;

public:
    /**
     * @brief constructor for the Room class
     * @param id the id of the room
     */
    Room(int id) : room_id(id) {}

    /**
     * @brief retrieves the id of the room
     * @return the id of the room
     */
    int get_id() const { return room_id; }

    /**
     * @brief adds a wall to the room
     * @param wall pointer to the Wall object
     * @return void
     */
    void add_wall(Wall *wall) {
        this->walls.push_back(wall);
    }

    /**
     * @brief adds a door to the room
     * @param door pointer to the Door object
     * @return void
     */
    void add_door(Door *door) {
        this->door = door;
    }

    /**
     * @brief destructor for the Room class
     */
    virtual ~Room() {
        for (auto wall : this->walls) {
            delete wall;
        }
    }
};

/**
 * @class Fairy_Room
 * @brief represent a fairy room in the maze
 * @details the Fairy_Room class is a subclass of Room
 * and is used to represent a fairy room in the maze
 */
class Fairy_Room : public Room {
public:
    /**
     * @brief constructor for the Fairy_Room class
     * @param id the id of the room
     */
    Fairy_Room(int id) : Room(id) {}

    /**
     * @brief prints the description of the fairy room
     * @return void
     */
    void print_description() override {
        std::cout << "This room has fairies in it" << std::endl;
        for (auto wall : this->walls) {
            wall->print_description();
        }
    }
};

/**
 * @class Dystopian_Room
 * @brief represent a dystopian room in the maze
 * @details the Dystopian_Room class is a subclass of Room
 * and is used to represent a dystopian room in the maze
 */
class Dystopian_Room : public Room {
public:
    /**
     * @brief constructor for the Dystopian_Room class
     * @param id the id of the room
     */
    Dystopian_Room(int id) : Room(id) {}

    /**
     * @brief prints the description of the dystopian room
     * @return void
     */
    void print_description() override {
        std::cout << "This room is run down and cracked" << std::endl;
        for (auto wall : this->walls) {
            wall->print_description();
        }
    }
};

#endif //ROOM_HPP
