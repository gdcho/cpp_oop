#include <iostream>
#include <vector>
using namespace std;

struct Unit {
    int health = 100;
    virtual void attack() { cout << "Unit doesn't know how to attack. Health: " << health << endl;}
     ~Unit(){ cout << "Unit destroyed" << endl;};
};

struct Archer : Unit {
    void attack() {cout << "Attack with bow & arrow. Health: " << health  << endl;}
    ~Archer(){ cout << "Archer destroyed" << endl;};
};

struct Knight : Unit {
    void attack() {cout << "Attack with sword. Health: " << health  << endl;}
    ~Knight(){ cout << "Knight destroyed" << endl;};
};

void allAttack(vector<Unit *> units) {
    //call attack on all units through polymorphic attack function
    for (Unit *u : units)
    {
        u->attack();
    }
}

int main() {

    vector<Unit *> units;
    //push different types of units into vector
    for(int i=0; i<2; i++)
    {
        units.push_back(new Knight);
    }

    for(int i=0; i<3; i++)
    {
        units.push_back(new Archer);
    }

    //call all units to attack
    allAttack(units);

    //delete dynamic memory of units
    for(Unit *u : units)
    {
        delete u;
    }

    return 0;
}