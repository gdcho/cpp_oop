#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
    ifstream myFile{"../test.txt"};
    streampos begin = myFile.tellg();
    myFile.seekg (0, ios::end);
    streampos end = myFile.tellg();
    myFile.close();
    cout << "size is: " << (end-begin) << " bytes.\n";
    return 0;
}
