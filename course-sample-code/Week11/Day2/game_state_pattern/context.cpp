//
// Created by jyim3 on 2023-11-15.
//
#include "state.hpp"
#include "context.hpp"

//FSM
FSM::FSM(State *s) {
    running = true;
    change_state(s);
}

void FSM::change_state(State *s) {
    string oldStateName = "";
    string newStateName = s->name;
    if(state == nullptr) {
        cout << "\n--- State Changed to " << newStateName << " ---" << endl;
    } else {
        oldStateName = state->name;
        state->end();
        delete state;
        cout << "\n--- State Changed from " << oldStateName << " to " << newStateName << " ---" << endl;
    }

    state = s;
    state->set_context(this); //state points back to this FSM context for communication
    state->begin();
}