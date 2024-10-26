#include <iostream>
#include "Circle.hpp"

using namespace std;
int main() {
    Circle my_first_circle;
    my_first_circle.set_radius(2);
    cout << my_first_circle.area() << endl;

    return 0;
}