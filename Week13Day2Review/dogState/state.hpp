//
// Created by jyim3 on 2023-12-03.
//

#ifndef DOGSTATE_STATE_HPP
#define DOGSTATE_STATE_HPP

#include <iostream>
using namespace std;

// Abstract State class
class DogState {
public:
    virtual void bark() const = 0;
    virtual void wagTail() const = 0;
    virtual void energy() const = 0;
};

// Concrete HappyState
class HappyState : public DogState {
public:
    void bark() const override {
        std::cout << "Dog is happily barking!" << std::endl;
    }

    void wagTail() const override {
        std::cout << "Dog is happily wagging its tail!" << std::endl;
    }

    void energy() const override {
        std::cout << "Dog is very energetic!" << std::endl;
    }
};

// Concrete SadState
class SadState : public DogState {
public:
    void bark() const override {
        std::cout << "Dog is whimpering sadly." << std::endl;
    }

    void wagTail() const override {
        std::cout << "Dog has its tail between its legs." << std::endl;
    }

    void energy() const override {
        std::cout << "Dog has low energy." << std::endl;
    }
};

#endif //DOGSTATE_STATE_HPP
