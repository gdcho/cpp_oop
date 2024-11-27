//Name: David Cho
//Student# : A01351217

#include <iostream>

#include "maze_factory.hpp"
#include "maze_game.hpp"

/**
 * @brief main function to create a fairy and dystopian maze
 * and print their descriptions
 * @return 0
 */
int main() {
    /* create a fairy and dystopian maze factory */
    Maze_Factory *p_Fairy_Factory = new Fairy_Maze_Factory;
    Maze_Factory *p_Dystopian_Factory = new Dystopian_Maze_Factory;

    /* create a maze game */
    Maze_Game game;

    /* create a fairy and dystopian maze */
    Maze *fairy_maze = game.create_maze(p_Fairy_Factory);
    cout << endl;
    Maze *dystopian_maze = game.create_maze(p_Dystopian_Factory);

    /* delete the maze factories and mazes */
    delete p_Fairy_Factory;
    delete p_Dystopian_Factory;
    delete fairy_maze;
    delete dystopian_maze;

    return 0;
}