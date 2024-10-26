#include <iostream>
using namespace std;

/*
 *     An interface for the Color dimension. This is the implementation
    layer that actually does all the work.
 */
struct Color {
    string color;
    virtual string get_color() = 0;
};

struct Red : Color {
    Red() {
        color = "#FF0000";
    }

    string get_color() override {
        return "Red";
    }
};

struct Blue : Color {
    Blue() {
        color = "#0000FF";
    }

    string get_color() {
        return "Blue";
    }
};

struct Shape {
    /*
     * The Shape class represents the Abstraction dimension.
     */
    Color* my_color;

    Shape(Color *color) {
        my_color = color; //here is the BRIDGE to the color object/class
    }

    virtual void draw() {
        cout << "I'm a Shape with color " << my_color->get_color() << endl;
    }

    virtual ~Shape() {
        delete my_color;
    }
};

struct Square : Shape {
    Square(Color *color) : Shape(color) {};
    void draw() override {
        cout << "I'm a Square with color " << my_color->get_color() << endl;
    }
};

struct Circle : Shape {
    Circle(Color *color) : Shape(color) {};
    void draw() override {
        cout << "I'm a Circle with color " << my_color->get_color() << endl;
    }
};

int main() {
    cout << "---- COMBO 1: Red Square ----" << endl;
    Square red_square{new Red()};
    red_square.draw();

    cout << "\n---- COMBO 2: Blue Circle ----" << endl;
    Circle blue_circle{new Blue()};
    blue_circle.draw();

    cout << "\n---- COMBO 3: Red Circle ----" << endl;
    Circle red_circle{new Red()};
    red_circle.draw();
    return 0;
}