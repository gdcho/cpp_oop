#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;
int main() {
    union unionName{
        int integer;
        char characters;
    } my_union;

    cout << my_union.integer << endl;
    cout << my_union.characters << endl;

    my_union.integer = 40;

    cout << my_union.integer << endl;
    cout << my_union.characters << endl;

    my_union.characters = 'A';
    cout << my_union.integer << endl;
    cout << my_union.characters << endl;

    return 0;
}