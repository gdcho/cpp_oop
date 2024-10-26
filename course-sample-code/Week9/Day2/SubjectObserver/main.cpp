#include <iostream>
#include "Game.hpp"
#include "HighScore.hpp"
#include "State.hpp"
#include "Screens.hpp"

int main() {
    Game game{State::start}; //subject
    HighScore highScore{State::start}; //observer
    Screens screens{State::start}; //observer

    //attach observers and subjects
    game.attach(&highScore);
    game.attach(&screens);

    //game begins. All observers of game notified game began
    game.begin();

    //high score no longer observing game
    game.detach(&highScore); //see output if commenting out this line
    cout << endl;

    //game ends. All observers of game notified game ended
    game.end();

    return 0;
}