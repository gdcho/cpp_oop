#include <iostream>
#include "donut.hpp"
#include "toppings.hpp"
//adapted from https://www.geeksforgeeks.org/decorator-pattern-set-3-coding-the-design/
using namespace std;

void createCustomDonut() {
    cout << "---Welcome to the custom donut shop!---" << endl;
    int choice = 0;

    const int RICE_DONUT = 1;
    const int WHEAT_DONUT = 2;
    const int SPRINKLES = 1;
    const int GUMMIES = 2;
    const int CHOCOLATE = 3;
    const int FINISH = 4;

    cout << "What donut would you like?" << endl;
    cout << "1 - Rice donut" << endl;
    cout << "2 - Wheat donut" << endl;
    cin >> choice;

    Component *customDonut = (choice == RICE_DONUT) ? (Component*)new RiceDonut : (Component*)new WheatDonut;

    do {
        cout << "Add toppings to donut?" << endl;
        cout << "1 - Add Sprinkles" << endl;
        cout << "2 - Add Gummies" << endl;
        cout << "3 - Add Chocolate" << endl;
        cout << "4 - Complete donut" << endl;
        cin >> choice;
        switch (choice) {
            case SPRINKLES:
                customDonut = new Sprinkles(customDonut);
                break;
            case GUMMIES:
                customDonut = new Gummies(customDonut);
                break;
            case CHOCOLATE:
                customDonut = new Chocolate(customDonut);
                break;
            default:
                choice = FINISH;
        }
        cout << customDonut->Description() << " Cost: $" << customDonut->getCost() << endl;
    }while(choice != FINISH);

    delete customDonut;
}

// Driver class and method
int main() {
    // create new Rice component
    Component *riceDonut = new RiceDonut;
    cout << riceDonut->Description() << " Cost: $" << riceDonut->getCost() << endl;

    // create new Wheatdonut component
    Component *wheatDonut = new WheatDonut;

    // decorate it with Sprinkles topping
    wheatDonut = new Sprinkles(wheatDonut);

    //decorate it with Gummies topping
    wheatDonut = new Gummies(wheatDonut);

    cout << wheatDonut->Description() << " Cost: $" << wheatDonut->getCost() << endl << endl;

    //createCustomDonut(); //create fully customizable run-time donut

    delete riceDonut;
    delete wheatDonut;

    return 0;
}