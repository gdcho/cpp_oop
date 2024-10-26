#include <iostream>

struct C
{
    C() { std::cout << "Default constructor.\n"; }
    C(const C&) { std::cout << "A copy was made.\n"; }
};

C f()
{
    return C{};
}

int main()
{
    std::cout << "Hello World!\n";

    //copy elision
    //C obj = C{};

    //RVO + copy elision
    //C obj2 = f();

//    //regular default constructor and copy
    C c;
    C obj3 = c;
    return 0;
}

// Hello World!
// Default constructor.
// A copy was made.
// A copy was made.

// or

// Hello World!
// Default constructor.
// A copy was made.

// or

// Hello World!
// Default constructor.
