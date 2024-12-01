#include <iostream>
#include <string>

using namespace std;

// Base class
class Animal {
public:
    virtual ~Animal() {} // Virtual destructor for polymorphism
    virtual void speak() { cout << "Animal speaks." << endl; }
};

// Derived class: Dog
class Dog : virtual public Animal {
public:
    void speak() override { cout << "Dog barks." << endl; }
    void wagTail() { cout << "Dog wags tail." << endl; }
};

// Another derived class: Cat
class Cat : virtual public Animal {
public:
    void speak() override { cout << "Cat meows." << endl; }
    void scratch() { cout << "Cat scratches." << endl; }
};

class CatDog : public Cat, public Dog {
public:
    void speak() override { cout << "CatDog meow woofs." << endl; }
};

class Unrelated {

};

void crosscastDogToCat(Dog* dogPtr) {
    // **CROSS CASTING**
    // Casting between sibling classes via their common base.
    if (Cat* cat = dynamic_cast<Cat*>(dogPtr)) {
        cat->scratch();
    } else {
        cout << "Cross cast failed! Cannot cast Dog* to Cat*." << endl;
    }
}

int main() {
    CatDog* catDogPtr = new CatDog;

    crosscastDogToCat(catDogPtr);

    Unrelated* unrelated = dynamic_cast<Unrelated*>(catDogPtr);
    if(unrelated == nullptr) {
        cout << "Dynamic cast failed. unrelated is not part of cat/dog hierarchy" << endl;
    }
    else{
        cout << "Dynamic cast succeeded" << endl;
    }

    Unrelated* unrelated1 = new Unrelated;
    crosscastDogToCat((Dog*)unrelated1); //Force casting unrelated to dog, then cross casting to cat

     delete catDogPtr;
     delete unrelated1;

    return 0;
}
