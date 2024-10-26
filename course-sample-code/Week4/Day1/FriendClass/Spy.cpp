//
// Created by A00257049 on 2019-01-22.
//

#include "Spy.hpp"

//Spy did not make boss their friend, so can't access PIN
void Boss::print(Spy *s) {
    cout << "Boss using Spy's pin: " << s->pin << endl;
}

void Spy::print(Boss *b) {
    //boss made Spy their friend, so Spy has access to Boss' private pin
    cout << "Spy using Boss' pin: " <<  b->pin << endl;
}