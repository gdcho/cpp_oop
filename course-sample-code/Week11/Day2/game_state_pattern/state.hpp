//
// Created by A00257049 on 2020-11-13.
//

#ifndef GAME_STATE_PATTERN_STATE_HPP
#define GAME_STATE_PATTERN_STATE_HPP

#include <iostream>
using namespace std;

struct FSM; //forward declaration
/*
    The abstract state class that contains references back to the context
    and methods to set the context
 */
struct State {
    FSM *context; //unique to the state pattern. states can have a pointer back to the context (FSM)
    string name;
    State(string name = "State", FSM *context = nullptr) : context(context), name(name) {}

    void set_context(FSM *c) { context = c; } //sets the context to point back at FSM

    virtual void begin() = 0;
    virtual void update() = 0;
    virtual void end() = 0;
    virtual ~State() {}
};

struct GameOver : State {
    GameOver ();

    void begin() override;
    void update() override;
    void end() override;
};


/*
    The concrete state. Each state performs different begin, end, and update function calls
    This state represents what happens when the player is actively playing during gameplay
    This is simulated by keeping the player alive, or having them die
 */
struct Gameplay : State {
    Gameplay ();

    void begin() override;
    void update() override;
    void end() override;
};


/*
    The concrete state. Each state performs different begin, end, and update function calls
    This state represents what happens when the enters the main menu
    The player has the option to start the game or quit the game
 */
//cout << "" << endl;
struct MainMenu : State {
    MainMenu();

    void begin() override;
    void update() override;
    void end() override;
};



#endif //GAME_STATE_PATTERN_STATE_HPP
