#include <iostream>

using namespace std;

class C
{
public:
    C() { std::cout << "Default constructor.\n"; }
    C(const C&) { std::cout << "A copy was made.\n"; }
    C(const C&&) { std::cout << "A move was made.\n"; }
};

C createCObject()
{
    return C{};
}

int main() {
    //Before C++ 11 - createCObject returns copy, and assignment operator performs another copy
    //Before C++ 11 there was no Copy elision/RVO
    //You can see this by adding "set(CMAKE_CXX_FLAGS "-fno-elide-constructors") # Disable copy elision" with no quotes into the CMakeLists.txt
    C obj2 = createCObject();
}