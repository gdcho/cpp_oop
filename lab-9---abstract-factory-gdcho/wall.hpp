//
// Created by David Cho on 2024-11-11.
//

#ifndef WALL_HPP
#define WALL_HPP

#include <iostream>
#include "maze_object.hpp"

using namespace std;

/**
 * @class Wall
 * @brief represent a wall in the maze
 * @details the Wall class is a subclass of Maze_Object
 * and is used to represent a wall in the maze
 */
class Wall : public Maze_Object {
public:
    /**
     * @brief constructor for the Wall class
     */
    Wall() = default;

    /**
     * @brief destructor for the Wall class
     */
    virtual ~Wall() = default;

    /**
     * @brief overloaded insertion operator for Wall objects
     * @param os the output stream
     * @param wall the Wall object
     * @return reference to the output stream
     */
    friend ostream &operator<<(ostream &os, const Wall &wall) {
        (void)wall;
        os << "Wall";
        return os;
    }
};

/**
 * @class Fairy_Wall
 * @brief represent a fairy wall in the maze
 * @details the Fairy_Wall class is a subclass of Wall
 * and is used to represent a fairy wall in the maze
 */
class Fairy_Wall : public Wall {
public:

    /**
     * @brief constructor for the Fairy_Wall class
     */
    Fairy_Wall() {}

    /**
     * @brief prints the description of the fairy wall
     * @return void
     */
    void print_description() override {
        cout << "This wall has fairy wings on it" << endl;
    }
};

/**
 * @class Dystopian_Wall
 * @brief represent a dystopian wall in the maze
 * @details the Dystopian_Wall class is a subclass of Wall
 * and is used to represent a dystopian wall in the maze
 */
class Dystopian_Wall : public Wall {
public:
    /**
     * @brief constructor for the Dystopian_Wall class
     */
    Dystopian_Wall() {}

    /**
     * @brief prints the description of the dystopian wall
     * @return void
     */
    void print_description() override {
        cout << "This wall has surveillance cameras on it" << endl;
    }
};

#endif //WALL_HPP
