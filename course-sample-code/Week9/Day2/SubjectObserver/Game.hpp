//
// Created by A00257049 on 2018-12-06.
//

#ifndef SUBJECTOBSERVER_GAME_HPP
#define SUBJECTOBSERVER_GAME_HPP

#include "Subject.hpp"

class Game : public Subject {
public:
    Game(State s) : Subject{s} {}
    void begin();
    void end();
};

#endif //SUBJECTOBSERVER_GAME_HPP
