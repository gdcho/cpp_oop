//
// Created by A00257049 on 2018-12-06.
//

#ifndef SUBJECTOBSERVER_HIGHSCORE_HPP
#define SUBJECTOBSERVER_HIGHSCORE_HPP

#include "Observer.hpp"

class HighScore : public Observer
{
public:
    HighScore(State s) : Observer(s) {}
    virtual void Update();
};

#endif //SUBJECTOBSERVER_HIGHSCORE_HPP
