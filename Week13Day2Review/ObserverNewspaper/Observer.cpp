//
// Created by A00257049 on 2020-12-02.
//

#include "Observer.hpp"
#include "Subject.hpp"

void Optimist::update(Subject *subject) {
    cout << "Optimist is happy: " << subject->getInfo() << endl;
}

void Pessimist::update(Subject *subject) {
    cout << "Pessimist is sad: " << subject->getInfo() << endl;
}