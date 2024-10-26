#include <iostream>
//dynamic cast does runtime type checking. pointer evaluates to null if can't convert

class Base { public: virtual ~Base() { } };

class Derived : public Base { public: virtual ~Derived() { } };

class Unrelated { public: virtual ~Unrelated() { } };

int main()
{
	Derived d;

	Base *basePointToDerived = dynamic_cast<Base *>(&d);
	Unrelated *unrelatedPointToDerived = dynamic_cast<Unrelated *>(&d);

	//compare to
//	Base *basePointToDerived = (Base *)(&d);
//	Unrelated *unrelatedPointToDerived = (Unrelated *)(&d);

	if (basePointToDerived != nullptr) {
		std::cout << "basePointToDerived - In the same inheritance hierarchy" << std::endl;
	}
	else {
		std::cout << "basePointToDerived - Not in the same inheritance hierarchy" << std::endl;
	}

    if (unrelatedPointToDerived != nullptr) {
        std::cout << "unrelatedPointToDerived - In the same inheritance hierarchy" << std::endl;
    }
    else {
        std::cout << "unrelatedPointToDerived - Not in the same inheritance hierarchy" << std::endl;
    }

}
