#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
    fstream myFile("../test.txt");

    // Sets the characters "Hello World" to the file
    myFile << "Hello World";

    // Seek to 6 characters from the beginning of the file
    myFile.seekg(6, ios::beg);
    cout << (char)myFile.get() << endl;

    // myFile.seekg(25);
    // cout << myFile.tellg() << endl;

    //move the pointer around
    // myFile.seekg(0, ios::beg);
    // cout << myFile.tellg() << endl;
    // myFile.seekg(0, ios::beg);
    // cout << myFile.tellg() << endl;
    // myFile.seekg(0, ios::end);
    // cout << myFile.tellg() << endl;

    // Read the next 5 characters from the file into a buffer
    char buffer[6];
    // cout << "Before read pos: " << myFile.tellg() << endl;
    myFile.read(buffer, 5);
    cout << "After read pos: " << myFile.tellg() << endl;
    for (int i : buffer)
    {
        cout << i << endl;
    }
    // End the buffer with a null terminating character
    // buffer[5] = 0;

    // // Output the contents read from the file and close it
    cout << buffer << endl;

    myFile.close();
}
