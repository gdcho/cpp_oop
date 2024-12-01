#include <iostream>
#include <string>
#include "context.hpp"
#include "state.hpp"

int main() {
    Dog dog;

    // Dog is initially happy
    dog.setState(new HappyState());

    // Simulate actions in different states
    dog.bark();
    dog.wagTail();
    dog.energy();

    // Change state to sad
    dog.setState(new SadState());

    cout << endl;

    // Simulate actions in the new state
    dog.bark();
    dog.wagTail();
    dog.energy();

    return 0;
}
