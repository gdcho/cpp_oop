//
// Created by A00257049 on 2018-12-06.
//

#include "Screens.hpp"
#include "Subject.hpp"
#include <iostream>

using namespace std;
void Screens::Update()
{
    if(subject == nullptr)
        return;

    state = subject->getState();

    switch (state)
    {
        case State::start:
        {
            cout << "Close game over screen. Show start screen" << endl;
            break;
        }
        case State::over:
        {
            cout << "Close start screen. Show game over screen" << endl;
            break;
        }
    }

}