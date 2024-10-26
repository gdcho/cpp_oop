#include <iostream>
using namespace std;

void addToNum(int numCopy)
{
    //numCopy gets a copy of num
    //numCopy value of 5

    numCopy++;

    //numCopy changes to 6
}

void addToNum(int *numPtrCopy)
{
    (*numPtrCopy)++;
}

int main() {
    int num = 5;
    int *numPtr = &num;

    addToNum(num);
    cout << num << endl;

    addToNum(numPtr);
    cout << num << endl;

   return 0;
}