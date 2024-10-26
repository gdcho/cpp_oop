//
// Created by A00257049 on 2019-01-21.
//

#include "Circle.hpp"

Circle::Circle() {
    radius = 10;
}
Circle::Circle(int r) : radius(r) {
}

void Circle::set_radius(int new_radius){
    radius = new_radius;
}

double Circle::area() {
    return 3.14 * radius * radius;
}