//
// Created by A00257049 on 2018-12-06.
//

#include "HighScore.hpp"
#include "Subject.hpp"
#include <iostream>

using namespace std;
void HighScore::Update()
{
    if(subject == nullptr)
        return;

    state = subject->getState();

    switch (state)
    {
        case State::start:
        {
            cout << "Load High Scores" << endl;
            break;
        }
        case State::over:
        {
            cout << "Save High Score" << endl;
            break;
        }
    }

}