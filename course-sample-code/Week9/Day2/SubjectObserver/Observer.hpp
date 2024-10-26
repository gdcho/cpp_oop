//
// Created by A00257049 on 2018-12-06.
//

#ifndef SUBJECTOBSERVER_OBSERVER_HPP
#define SUBJECTOBSERVER_OBSERVER_HPP

#include "State.hpp"

class Subject;

class Observer
{
public:
    State state;
    Subject *subject;
    Observer(State s) : state{s}{}
    void RegisterSubject(Subject *sub) {subject = sub;}
    virtual void Update() = 0;
};

#endif //SUBJECTOBSERVER_OBSERVER_HPP
