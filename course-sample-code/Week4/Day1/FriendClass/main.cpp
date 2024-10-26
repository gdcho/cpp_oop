#include <iostream>
#include "Spy.hpp"
int main() {
    Boss boss{1111};
    Spy spy{2222};
    //cout << boss.pin; //can't access boss' pin from main
    spy.print(&boss);
    boss.print(&spy);

    return 0;
}