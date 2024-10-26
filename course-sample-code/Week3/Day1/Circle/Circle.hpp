//
// Created by A00257049 on 2019-01-21.
// breakdown of basic class structure. Declaring in header, defining in CPP requires :: scope operator
// set visibility with private, protected, public
//

#ifndef CIRCLE_CIRCLE_HPP
#define CIRCLE_CIRCLE_HPP
class Circle
{
private:
    double radius;
public:
    Circle();
    Circle(int r);
    void set_radius(int);
    double area();
};
#endif //CIRCLE_CIRCLE_HPP
