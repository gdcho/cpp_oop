//
// Created by jyim3 on 2023-12-03.
//

#include "mediator.hpp"

//Initialize all components
ConcreteMediator::ConcreteMediator() {
    trafficLight = new TrafficLight;
    car = new Car;

    trafficLight->setMediator(this);
    car->setMediator(this);
}

//Car and TrafficLight call notify when something changes
//Mediator contains logic to determine which component called it,
//and what calls should be made next
void ConcreteMediator::notify(BaseComponent *component) {
    //if TrafficLight called, then Mediator calls the Car to change
    //its state
    if(component == trafficLight){
        if(trafficLight->getColor() == RED) {
            car->stop();
        }
        else if(trafficLight->getColor() == YELLOW) {
            car->slowDown();
        }
        else if(trafficLight->getColor() == GREEN) {
            car->go();
        }
    }
    //if Car called, then print out the Car's state
    else if(component == car) {
        cout << car->getState() << endl;
    }
}

//Entry point into mediator controlling the system
void ConcreteMediator::execute() {
    //Cause the TrafficLight to change its colors:
    //Traffic light changes its internal color, then notifies mediator
    //mediator reacts to the traffic light's color and calls specific car function
    //car changes its state, then notifies mediator
    //mediator reacts to the car, gets and prints out car's state
    trafficLight->changeRed(); //this finishes

    trafficLight->changeYellow();

    trafficLight->changeGreen();
}