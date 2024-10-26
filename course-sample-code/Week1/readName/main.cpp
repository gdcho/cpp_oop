#include <iostream>
#include <iomanip>

using namespace std;
int main() {
    constexpr int firstNameLength = 5;
    char firstName[firstNameLength];
    //cin >> firstName;
    cin >> setw(5) >> firstName;
    cout << firstName;
    return 0;
}