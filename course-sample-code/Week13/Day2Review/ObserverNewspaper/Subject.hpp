//
// Created by A00257049 on 2020-12-02.
//

#ifndef OBSERVERNEWSPAPER_SUBJECT_HPP
#define OBSERVERNEWSPAPER_SUBJECT_HPP

#include "Observer.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Subject {
protected:
    vector <Observer *> observers;
public:
    void attach(Observer *o);
    void detach(Observer *o);
    void notify();
    virtual string getInfo() = 0;
};

//Subject
class Newspaper : public Subject {
    string currentNews;
public:
    void setNews(string val);
    string getInfo() override;
};

#endif //OBSERVERNEWSPAPER_SUBJECT_HPP
