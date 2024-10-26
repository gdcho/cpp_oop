//
// Created by jyim3 on 2023-11-15.
//

#ifndef Q1_CONTEXT_HPP
#define Q1_CONTEXT_HPP

#include "state.hpp"
//  FSM (Finite state machine) is the context. This will be the container that changes its states
struct FSM {
    State* state = nullptr;
    bool running;

    FSM(State *s);

    /*
        Changes the finite state machine's state
        :param state: the new state fsm is changing to use
     */
    void change_state(State *s);

    //no code here that FSM does, forwards work to the state
    void update() {
        return state->update();
    };

    void set_running(bool r) {
        running = r;
    }

    bool is_running() {
        return running;
    }

    ~FSM() {
        delete state;
    }
};

#endif //Q1_CONTEXT_HPP
