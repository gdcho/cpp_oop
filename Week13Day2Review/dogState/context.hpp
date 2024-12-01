//
// Created by jyim3 on 2023-12-03.
//

#ifndef DOGSTATE_CONTEXT_HPP
#define DOGSTATE_CONTEXT_HPP

#include <iostream>
#include "state.hpp"
using namespace std;

// Context class (Dog)
class Dog {
private:
    DogState* currentState = nullptr;

public:
    Dog() : currentState(nullptr) {}
    ~Dog() {
        if(currentState != nullptr)
            delete currentState;
    }

    void setState(DogState* newState) {
        //delete previous state
        if(currentState != nullptr){
            delete currentState;
        }
        currentState = newState; //point to new state
    }

    void bark() const {
        currentState->bark();
    }

    void wagTail() const {
        currentState->wagTail();
    }

    void energy() const {
        currentState->energy();
    }
};

#endif //DOGSTATE_CONTEXT_HPP
