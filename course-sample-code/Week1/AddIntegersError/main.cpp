#include <iostream>
#include <limits>
using namespace std;
int main() {
    int n;
    cout << "Enter a number: " << endl;
    while(cin >> n)
    {
        cout << "Enter a number: " << n << endl;
    }

    string name = "";

    cout << "Enter a string, type ''quit'' to leave: " << endl;
    while(cin >> name)
    {
        if(name == "quit") {
            break;
        }
        cout << "Enter a string, type ''quit'' to leave: " << name << endl;
    }

    cout << "Ending program\n";
    return 0;
}