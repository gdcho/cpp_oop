#include <iostream>
#include "state.hpp"
#include "context.hpp"

int main() {
    cout << "Create FSM and set first state to be Main Menu" << endl;
    FSM fsm(new MainMenu);

    while(fsm.is_running()) {
        fsm.update();
    }

    return 0;
}