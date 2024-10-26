#include <iostream>
using namespace std;
struct Pizza {

    string base;
    string sauce;
    string sauce2;
    string toppings;
    string toppings2;

    //Constructor accepts too many parameters. It can become overwhelming with
    //many options
    Pizza(string base, string sauce, string sauce2,
            string toppings, string toppings2) {
        this->base = base;
        this->sauce = sauce;
        this->sauce2 = sauce2;
        this->toppings = toppings;
        this->toppings2 = toppings2;
    }
};

int main() {
    Pizza *p = new Pizza("full", "tomato", "butter", "pepporoni", "sausage");
    delete p;
    return 0;
}