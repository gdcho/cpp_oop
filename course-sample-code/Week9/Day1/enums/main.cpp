#include <iostream>

using namespace std;

void unscopedEnums() {
    enum color { red, green, blue};
    //enum color2 {red, green, blue}; //conflict with color
    color r = blue;

    switch(r)
    {
        case red:
            std::cout << "red\n";
            break;
        case green:
            std::cout << "green\n";
            break;
        case blue :
            std::cout << "blue\n";
            break;
    }

    int num = r;
    cout << "num: " << num << endl;
}

void scopedEnums() {
    enum class color { red, green, blue};
    enum class color2 {red, green, blue};
    color r = color::blue;

    switch(r)
    {
        case color::red:
            std::cout << "red\n";
            break;
        case color::green:
            std::cout << "green\n";
            break;
        case color::blue :
            std::cout << "blue\n";
            break;
    }

    //int num = r; //error need to cast scoped enum to int
    int num = static_cast<int>(r);
    cout << "num: " << num << endl;
}
int main() {
    unscopedEnums();
    scopedEnums();
    return 0;
}