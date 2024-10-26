    #include <iostream>
    #include <string>
    #include <sstream>

    using namespace std;

    void example()
    {
        istringstream iss;
        int n;
        string aString;
        string bString;
        string cString;
        iss.str("   123a b c");
        iss >> n >> aString >> bString >> cString;
        cout << n << endl;
        cout << aString << bString << cString << endl;
        cout << iss.str() << endl;
        iss.str("changed string,567");
        cout << iss.str();
    }

    int main() {
        string line;
        int n, sum{0};
        istringstream iss;
        cout << "enter a number: ";
        while (getline(cin, line) {
            iss.clear(); //clears error flags if space after number
            iss.str(line);
            cout << "line:" << line << endl;
            if (iss >> n) {
                sum += n;
                cout << "sum is: " << sum << endl;
            }
            cout << "enter a number: ";
        }

        // string line;
        // cin >> line;
        // const char * c_line = line.c_str();
        // cout << c_line << endl;

        //example();
        return 0;
    }

