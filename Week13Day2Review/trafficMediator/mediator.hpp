//
// Created by jyim3 on 2023-12-03.
//

#ifndef TRAFFICMEDIATOR_MEDIATOR_HPP
#define TRAFFICMEDIATOR_MEDIATOR_HPP
#include "components.hpp"
// Mediator interface
class Mediator {
public:
    virtual void notify(BaseComponent* component) = 0;
};

// Concrete mediator
class ConcreteMediator : public Mediator {
    TrafficLight* trafficLight;
    Car* car;
public:
    ConcreteMediator();
    ~ConcreteMediator() {
        delete trafficLight;
        delete car;
    }
    void notify(BaseComponent* component) override;
    void execute();
};

#endif //TRAFFICMEDIATOR_MEDIATOR_HPP
