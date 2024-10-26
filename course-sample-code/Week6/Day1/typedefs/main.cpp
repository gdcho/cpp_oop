#include <iostream>
#include <vector>
#include <iterator>
#include <deque>

using namespace std;

// declares int_t to be an alias for the type int
typedef int int_t;

// arr_t is array of 3 int
typedef int arr_t[3];

// reference is a reference to an int
typedef int& reference;
typedef int* pointer;

// struct Foo and Foo are the same thing
struct Foo
{
   int x;
};

typedef struct Foo Foo; //this is what we did in C, unnecessary in C++

void printFoo(Foo foo) {
    cout << "Foo x val: "<< foo.x << endl;
}

int main() {
    int_t intT = 99;
    reference intRef = intT;
    pointer intPtr = &intT;
    arr_t arrT = {0,1,2}; //int arr_T[3];

    cout << "change int_t through int_ref reference: " << endl;
    cout << intT << endl;
    intRef++;
    cout << intT << endl;

    //structs
    Foo f;
    f.x = 99;
    printFoo(f);

    cout << "vector contents: " << endl;
    vector<int> myVec = {1,2,3,4,5};
    vector<int>::iterator myIter = myVec.begin(); //gets random access iterator
    for (myIter; myIter != myVec.end(); myIter++) {
        cout << *myIter << endl;
    }

    return 0;
}