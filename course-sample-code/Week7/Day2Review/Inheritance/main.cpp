/*
 * This sample code covers inheritance
 * 1 - Shows unnecessary copies when calling functions and pushing objects into vectors
 * 2 - No polymorphism in Animal vector because Canine and Bird converted to Animal
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

//non pointer/dynamic code
Canine createCanine() {
    return Canine{};
}

Bird createBird() {
    return Bird{};
}

void animalsSpeak(Animal &a)
{
    a.speak();
}

int main() {
    vector<Animal> animals;
    //animals.reserve(4); //Can set initial vector capacity to avoid extra vector copies
    cout << "Push canine" << endl;
    animals.push_back(createCanine());
    cout << "Push bird 1" << endl;
    animals.push_back(createBird());
    cout << "Push bird 2" << endl;
    animals.push_back(createBird());
    cout << "Finish pushing animals" << endl;

    for(Animal &a : animals)
    {
        animalsSpeak(a);
    }

    return 0;
}