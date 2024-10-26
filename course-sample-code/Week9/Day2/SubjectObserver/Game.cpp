//
// Created by A00257049 on 2018-12-06.
//

#include "Game.hpp"
#include "Subject.hpp"
#include <iostream>

using namespace std;
void Game::begin()
{
    setState(State::start);
    cout << "Begin Game" << endl;
    notify();
}

void Game::end()
{
    setState(State::over);

    cout << "End Game" << endl;
    notify();
}