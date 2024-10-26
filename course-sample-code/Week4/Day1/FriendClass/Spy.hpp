//
// Created by A00257049 on 2019-01-22.
//
#include <iostream>
#ifndef FRIENDCLASS_SPY_HPP
#define FRIENDCLASS_SPY_HPP

using namespace std;

class Spy; //forward declaration

class Boss {
private:
   friend class Spy;
   int pin; //private
public:
   Boss(int p) : pin(p){}
   void print(Spy *s);
};

class Spy {
    //friend class Boss;
   int pin; //private
public:
   Spy(int p) : pin(p){}
   void print(Boss *b);
};

#endif //FRIENDCLASS_SPY_HPP
