#include <iostream>
using namespace std;
struct Pizza {

    string base;
    bool is_halfnhalf;
    string sauce;
    string sauce2;
    string toppings;
    string toppings2;
    string cheese1;
    string cheese2;
    bool is_calzone;

    //Constructor accepts too many parameters. It can become overwhelming with
    //many options
    Pizza(string base, bool is_halfnhalf, string sauce, string sauce2,
            string toppings, string toppings2, string cheese1, string cheese2,
            bool is_calzone) {
        this->base = base;
        this->is_halfnhalf = is_halfnhalf;
        this->sauce = sauce;
        this->sauce2 = sauce2;
        this->toppings = toppings;
        this->toppings2 = toppings2;
        this->cheese1 = cheese1;
        this->is_calzone = is_calzone;
    }
};

int main() {
    Pizza *p = new Pizza("full", false, "tomato", "butter", "pepporoni", "sausage",
            "mozz", "cheddar", false);
    return 0;
}