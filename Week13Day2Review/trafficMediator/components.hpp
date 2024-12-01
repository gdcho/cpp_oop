//
// Created by jyim3 on 2023-12-03.
//

#ifndef TRAFFICMEDIATOR_COMPONENTS_HPP
#define TRAFFICMEDIATOR_COMPONENTS_HPP
using namespace std;
#include <iostream>;

class Mediator; //Forward Declaration

const string RED = "Red";
const string YELLOW = "Yellow";
const string GREEN = "Green";

class BaseComponent {
protected:
    Mediator *mediator;

public:
    BaseComponent(Mediator *mediator = nullptr) : mediator(mediator) {}
    void setMediator(Mediator *mediator) {this->mediator = mediator;

    }
};

// Concrete Mediator
class TrafficLight : public BaseComponent {
private:
    string color;
public:
    TrafficLight(){}
    void changeRed();
    void changeYellow();
    void changeGreen();
    string getColor() {return color;}
};

// Concrete Car
class Car : public BaseComponent {
    string state = "";
public:
    Car(){}
    void stop();
    void slowDown();
    void go();
    string getState() {return state;}
};

#endif //TRAFFICMEDIATOR_COMPONENTS_HPP
