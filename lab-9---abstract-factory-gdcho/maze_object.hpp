//
// Created by David Cho on 2024-11-11.
//

#ifndef MAZE_OBJECT_HPP
#define MAZE_OBJECT_HPP

/**
 * @class Maze_Object
 * @brief represent a maze object
 * @details the Maze_Object class is an abstract class
 * that is used to represent an object in the maze
 */
class Maze_Object {
public:

    /**
     * @brief prints the description of the maze object
     * @return void
     */
    virtual void print_description() = 0;

    /**
     * @brief destructor for the Maze_Object class
     */
    virtual ~Maze_Object() = default;
};

#endif //MAZE_OBJECT_HPP
