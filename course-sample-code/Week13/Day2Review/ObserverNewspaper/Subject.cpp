//
// Created by A00257049 on 2020-12-02.
//

#include "Subject.hpp"

void Subject::attach(Observer *o) {
    observers.push_back(o);
    cout << "After attach, num observers: " << observers.size() << endl;
}
void Subject::detach(Observer *o) {
    for(int i=0; i<observers.size(); i++)
    {
        if(observers[i] == o)
        {
            observers.erase(observers.begin()+i);
            cout << "After detach, num observers: " << observers.size() << endl;
            return;
        }
    }
}

void Subject::notify() {
    for (Observer *o : observers)
    {
        o->update(this);
    }
}

void Newspaper::setNews(string val) {
    currentNews = val;
    notify(); //notify observers that something important has happened
}
string Newspaper::getInfo() {
    return currentNews;
}
