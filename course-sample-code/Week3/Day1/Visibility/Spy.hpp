//
// Created by A00257049 on 2019-01-21.
// how visibility changes with keyword for extending class
//
#include <iostream>
#ifndef VISIBILITY_SPY_HPP
#define VISIBILITY_SPY_HPP
using namespace std;

class Spy {
public:
    void publicPrint() {cout << "public" << endl;}
protected:
    void protectedPrint() {cout << "protected" << endl;}
private:
    void privatePrint() {cout << "private" << endl;}
};

class PublicSpy : public Spy {
public:
    void print() {
        publicPrint(); //still public
        protectedPrint(); //still protected
        //privatePrint();
    }
};

class ProtectedSpy : protected Spy {
public:
    void print() {
        publicPrint(); //changed to protected
        protectedPrint(); //still protected
        //privatePrint();
    }
};

//class PrivateSpy : Spy { //classes inherit privately by default
class PrivateSpy : private Spy {
public:
    void print() {
        publicPrint(); //changed to private
        protectedPrint(); //changed to private
        //privatePrint();
    }
};

class PrivateSpy2 : private PrivateSpy {
public:
    void print() {
        //publicPrint();
        //protectedPrint();
        //privatePrint();
    }
};
#endif //VISIBILITY_SPY_HPP
