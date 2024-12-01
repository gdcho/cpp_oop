//
// Created by A00257049 on 2020-12-02.
//

#ifndef OBSERVERNEWSPAPER_OBSERVER_HPP
#define OBSERVERNEWSPAPER_OBSERVER_HPP

#include <iostream>
class Subject;

using namespace std;

class Observer {
public:
    virtual void update(Subject *subject) = 0;
    virtual ~Observer() = default;
};

class Optimist : public Observer {
    void update(Subject *subject) override;
};

class Pessimist : public Observer {
    void update(Subject *subject) override;
};

#endif //OBSERVERNEWSPAPER_OBSERVER_HPP
