//
// Created by A00257049 on 2018-12-06.
//

#ifndef SUBJECTOBSERVER_SCREENS_HPP
#define SUBJECTOBSERVER_SCREENS_HPP

#include "Observer.hpp"

class Screens : public Observer
{
public:
    Screens(State s) : Observer(s) {}
    virtual void Update();
};

#endif //SUBJECTOBSERVER_SCREENS_HPP
