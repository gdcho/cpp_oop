/*
 * This sample code covers inheritance
 * The importance of using pointers to:
 * 1 - avoid unnecessary copies when calling functions and pushing objects into vectors
 * 2 - enabling polymorphic function calls with virtual functions
 * 3 - properly destroying dynamic memory with a virtual destructor
 */

#include <iostream>
#include <vector>
using namespace std;

class Animal {
public:
    Animal() = default;
    Animal(const Animal &a) {cout << "Copy Animal" << endl;}
    virtual void speak(){cout << "Animal speak?" << endl;}
    //virtual ~Animal(){cout << "Animal destroyed" << endl;}
};

class Bird : public Animal {
public:
    Bird() = default;
    Bird(const Bird &b) {cout << "Copy Bird" << endl;}
    void speak() { cout << "Chirp" << endl;}
    //~Bird(){cout << "Bird destroyed" << endl;}
};

class Canine : public Animal {
public:
    Canine() = default;
    Canine(const Canine &c) {cout << "Copy Canine" << endl;}
    void speak() { cout << "Woof" << endl;}
    //~Canine(){cout << "Canine destroyed" << endl;}
};

void animalsSpeak(Animal &a)
{
    a.speak();
}

//pointer/dynamic code
Canine* createDynamicCanine() {
    return new Canine{};
}

Bird* createDynamicBird() {
    return new Bird{};
}

void animalsPolySpeak(Animal *a)
{
    a->speak();
}

int main() {
    vector<Animal*> animals;
    cout << "Push canine" << endl;
    animals.push_back(createDynamicCanine()); //pushed back canine pointer to canine object
    cout << "Push bird 1" << endl;
    animals.push_back(createDynamicBird());
    cout << "Push bird 2" << endl;
    animals.push_back(createDynamicBird());
    cout << "Finish pushing animals" << endl;

    for(Animal *a : animals)
    {
        //animalsSpeak(*a); //same as below but using references
        animalsPolySpeak(a);
    }

    for(Animal *a : animals)
    {
        delete a;
    }

    return 0;
}