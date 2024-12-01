//
// Created by jyim3 on 2023-12-03.
//

#include "components.hpp"
#include "mediator.hpp"

//Traffic light functions
//Traffic light changes its color then calls mediator after
void TrafficLight::changeRed() {
    color = RED;
    cout << "Traffic Light changed to " << color << "." << std::endl;
    mediator->notify(this);
}

void TrafficLight::changeYellow() {
    color = YELLOW;
    cout << "Traffic Light changed to " << color << "." << std::endl;
    mediator->notify(this);
}

void TrafficLight::changeGreen() {
    color = GREEN;
    cout << "Traffic Light changed to " << color << "." << std::endl;
    mediator->notify(this);
}

//Car functions
//Car changes its state, then calls mediator after
void Car::stop() {
    state = "Car stopping";
    mediator->notify(this);
}
void Car::slowDown() {
    state = "Car slowing down";
    mediator->notify(this);
}
void Car::go() {
    state = "Car going";
    mediator->notify(this);
}
