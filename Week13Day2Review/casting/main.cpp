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
class Dog : public Animal {
public:
    void speak() override { cout << "Dog barks." << endl; }
    void wagTail() { cout << "Dog wags tail." << endl; }
};

// Another derived class: Cat
class Cat : public Animal {
public:
    void speak() override { cout << "Cat meows." << endl; }
    void scratch() { cout << "Cat scratches." << endl; }
};

void dynamicDowncast(Animal *animalPtr) {
    // **DYNAMIC DOWNCASTING** (Base -> Derived)
    // Risky, requires explicit casting. Use `dynamic_cast` for safety with polymorphic types.
    if (Dog* dogPtr = dynamic_cast<Dog*>(animalPtr)) { // Downcast Animal* to Dog*
        dogPtr->wagTail(); // Safe, as animalPtr actually points to a Dog
    } else {
        cout << "Downcast failed!" << endl;
    }
}

void staticDowncast(Animal *animalPtr) {
    // **STATIC DOWN CASTING**
    // Used when type safety is assured by the programmer but without runtime type checks.
    // Only use when you are 100% sure about the type relationship.
    Dog* staticDogPtr = static_cast<Dog*>(animalPtr);
    staticDogPtr->wagTail(); // Works, but if animalPtr points to a Cat, this is undefined behavior!
}

int main() {
    // **UPCASTING** (Derived -> Base)
    // A derived class object is converted to a base class pointer/reference.
    //Animal dog;

    //Animal* animalPtr = dynamic_cast<Animal*>(&dog); // Explicitly Upcast Dog* to Animal*
    //Animal* animalPtr = &dog; // Implicitly Upcast Dog* to Animal*

    //animalPtr->speak();       // Calls Dog's overridden speak() method due to polymorphism

    //dynamicDowncast(animalPtr);

    //staticDowncast(animalPtr);

    Cat c;
    staticDowncast(&c); // dog wags tail??? not safe
    dynamicDowncast(&c); // downcast failed

    return 0;
}
