#include <iostream>
#include <fstream>

using namespace std;
int main() {
    ifstream infile("../input.txt");
    ofstream outfile("../output.txt");
    outfile << infile.rdbuf();
    return 0;
}