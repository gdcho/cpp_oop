//
// Created by David Cho on 2024-11-11.
//

#ifndef MAZE_FACTORY_HPP
#define MAZE_FACTORY_HPP

#include "maze.hpp"
#include "wall.hpp"
#include "room.hpp"
#include "door.hpp"

/**
 * @class Maze_Factory
 * @brief represent a maze factory
 * @details the Maze_Factory class is an abstract class
 * that is used to create different types of mazes
 */
class Maze_Factory {
public:

    /**
    * @brief creates a new Maze object
    * @return pointer to a Maze object
    */
    virtual Maze *make_maze() = 0;

    /**
     * @brief creates a new Wall object
     * @return pointer to a Wall object
     */
    virtual Wall *make_wall() = 0;

    /**
     * @brief creates a new Room object
     * @param id the id of the room
     * @return pointer to a Room object
     */
    virtual Room *make_room(int id) = 0;

    /**
     * @brief creates a new Door object
     * @param room1 pointer to the first Room object
     * @param room2 pointer to the second Room object
     * @return pointer to a Door object
     */
    virtual Door *make_door(Room *room1, Room *room2) = 0;

    /**
     * @brief destructor for the Maze_Factory class
     */
    virtual ~Maze_Factory() = default;
};

/**
 * @class Fairy_Maze_Factory
 * @brief represent a fairy maze factory
 * @details the Fairy_Maze_Factory class is a subclass of Maze_Factory
 * and is used to create fairy mazes
 */
class Fairy_Maze_Factory : public Maze_Factory {
public:

    /**
     * @brief constructor for the Fairy_Maze_Factory class
     */
    Fairy_Maze_Factory() = default;

    /**
     * @brief creates a new Fairy_Maze object
     * @return pointer to a Fairy_Maze object
     */
    Maze *make_maze() override {
        return new Fairy_Maze;
    }

    /**
     * @brief creates a new Fairy_Wall object
     * @return pointer to a Fairy_Wall object
     */
    Wall *make_wall() override {
        return new Fairy_Wall;
    }

    /**
     * @brief creates a new Fairy_Room object
     * @param id the id of the room
     * @return pointer to a Fairy_Room object
     */
    Room *make_room(int id) override {
     return new Fairy_Room(id);
    }

    /**
     * @brief creates a new Fairy_Door object
     * @param room1 pointer to the first Room object
     * @param room2 pointer to the second Room object
     * @return pointer to a Fairy_Door object
     */
    Door *make_door(Room *room1, Room *room2) override {
        /* create a new Fairy_Door object */
        Door* door = new Fairy_Door;
        /* add the door to the rooms */
        door->addRoom1(room1);
        door->addRoom2(room2);
        room1->add_door(door);
        room2->add_door(door);
        return door;
    }
};

/**
 * @class Dystopian_Maze_Factory
 * @brief represent a dystopian maze factory
 * @details the Dystopian_Maze_Factory class is a subclass of Maze_Factory
 * and is used to create dystopian mazes
 */
class Dystopian_Maze_Factory : public Maze_Factory {
public:

    /**
     * @brief constructor for the Dystopian_Maze_Factory class
     */
    Dystopian_Maze_Factory() = default;

    /**
     * @brief creates a new Dystopian_Maze object
     * @return pointer to a Dystopian_Maze object
     */
    Maze *make_maze() override {
        return new Dystopian_Maze;
    }

    /**
     * @brief creates a new Dystopian_Wall object
     * @return pointer to a Dystopian_Wall object
     */
    Wall *make_wall() override {
        return new Dystopian_Wall;
    }

    /**
     * @brief creates a new Dystopian_Room object
     * @param id the id of the room
     * @return pointer to a Dystopian_Room object
     */
    Room *make_room(int id) override {
     return new Dystopian_Room(id);
    }

    /**
     * @brief creates a new Dystopian_Door object
     * @param room1 pointer to the first Room object
     * @param room2 pointer to the second Room object
     * @return pointer to a Dystopian_Door object
     */
    Door *make_door(Room *room1, Room *room2) override {
       /* create a new Dystopian_Door object */
       Door* door = new Dystopian_Door;
       /* add the door to the rooms */
       door->addRoom1(room1);
       door->addRoom2(room2);
       room1->add_door(door);
       room2->add_door(door);
       return door;
    }
};

#endif //MAZE_FACTORY_HPP
