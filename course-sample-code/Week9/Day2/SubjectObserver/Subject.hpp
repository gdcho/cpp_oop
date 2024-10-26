//
// Created by A00257049 on 2018-12-06.
//

#ifndef SUBJECTOBSERVER_SUBJECT_HPP
#define SUBJECTOBSERVER_SUBJECT_HPP

#include <vector>
#include "Observer.hpp"
#include "State.hpp"


using namespace std;
class Subject {
public:
    vector<Observer*>observers;

    Subject(State s) : state{s} {}

    void attach(Observer *o) {
        o->RegisterSubject(this);
        observers.push_back(o);
    }

    void detach(Observer *o){
        int deleteIndex = -1;
        for (int i=0; i<observers.size(); i++) {
            if(observers[i] == o)
            {
                deleteIndex = i;
                break;
            }
        }
        o->subject = nullptr;
        observers.erase(observers.begin()+deleteIndex);
    }

    void notify()
    {
        for(Observer *o : observers)
        {
            o->Update();
        }
    }

    void setState(State g)
    {
        state = g;
    }

    State getState()
    {
        return state;
    }

    virtual ~Subject() = 0;

protected:
    State state;
};

#endif //SUBJECTOBSERVER_SUBJECT_HPP
