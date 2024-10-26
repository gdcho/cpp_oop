//
// Created by A00257049 on 2020-11-13.
//

#include "stateAndContext.hpp"

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

//GameOver
GameOver::GameOver () : State("GameOver") {}

void GameOver::begin() {
    cout << "Performing game over initialization" << endl;
    cout << "Show high score screens" << endl;
}

void GameOver::update() {
    cout << "Performing game over update" << endl;
    cout << "Press 1 - Return to main menu" << endl;
    cout << "Press 2 - Quit" << endl;
    int choice;
    cin >> choice;
    if(choice == 1)
        //unique to the state pattern. states have a reference back to the context (FSM)
        //this reference is used to call the context to change the state
        context->change_state(new MainMenu);
    else
        //unique to the state pattern. states have a reference back to the context (FSM)
        //this reference is used to call the context to stop running
        context->set_running(false);
}

void GameOver::end() {
    cout << "Performing game over clean up code" << endl;
    cout << "close high score screens" << endl;
}

//Gameplay
Gameplay::Gameplay () : State("Gameplay") {}

void Gameplay::begin() {
    cout << "Performing gameplay initialization" << endl;
    cout << "Show UI, health bars, scores" << endl;
}
void Gameplay::update() {
    cout << "Performing gameplay update" << endl;
    cout << "Press 1 - Player still alive" << endl;
    cout << "Press 2 - Player dies" << endl;
    int choice;
    cin >> choice;
    if(choice == 2)
        //unique to the state pattern. states have a reference back to the context (FSM)
        //this reference is used to call the context to change the state
        context->change_state(new GameOver);
}
void Gameplay::end() {
    cout << "Performing gameplay clean up code" << endl;
    cout << "close UI, health bars, scores" << endl;
}

//Main menu
MainMenu::MainMenu() : State("MainMenu") {}

void MainMenu::begin() {
    cout << "Performing main menu initialization" << endl;
    cout << "Show game title, button to quit game, button to start gameplay" << endl;
}
void MainMenu::update() {
    cout << "Performing main menu update" << endl;
    cout << "Press 1 - Enter gameplay" << endl;
    cout << "Press 2 - Quit" << endl;
    int choice;
    cin >> choice;
    if(choice == 1)
        //unique to the state pattern. states have a reference back to the context (FSM)
        //this reference is used to call the context to change the state
        context->change_state(new Gameplay);
    else
        //unique to the state pattern. states have a reference back to the context (FSM)
        //this reference is used to call the context to stop running
        context->set_running(false);
}
void MainMenu::end() {
    cout << "Performing main menu clean up code" << endl;
    cout << "close game title, button to quit game" << endl;
}