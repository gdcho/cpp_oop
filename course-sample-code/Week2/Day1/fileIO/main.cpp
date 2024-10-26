#include <iostream>
#include <fstream>

using namespace std;
int main() {
    fstream f{"../data.txt"}; // Opens data for writing
    ofstream outFile{"../output.txt"};


    if (!f.is_open()) { // Or if (!f) …
        cerr << "Unable to open file" << endl;
        exit(1);
    } else // everything has opened fine for f stream
    {
        char c;
        while ((c = f.get()) != EOF)
        {
            isdigit(c) ? outFile.put('*') : outFile.put(c);
            // isdigit(c) ? outFile << '*' : outFile << c;
        }
    }
    outFile.close();
    f.close();
    return 0;
}