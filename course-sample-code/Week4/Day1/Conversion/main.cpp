#include <iostream>

using namespace std;
void print1(int *nums)
{
    cout << "print 1" << endl;
    for(int i=0; i<3; i++) {
        cout << nums[i] << endl;
    }
}

void print2(const int num)
{
    cout << "print 2" << endl;
    cout << num << endl;
}

void print3(const int* num)
{
    cout << "print 3" << endl;
    cout << *num << endl;
}

void print4(int nums[]) {
    cout << "print 4" << endl;
    for(int i=0; i<3; i++) {
        cout << nums[i] << endl;
    }
}

void print5(int num) {
    cout << "print 5" << endl;
    cout << num << endl;
}

void print6(int *num) {
    cout << "print 6" << endl;
    cout << num << endl;
}

int function(int x, int y)
{
    cout << "function int" << endl;
}

double function(double x, double y)
{
    cout << "function double" << endl;
}

int main() {
    int nums[] = {1,2,3};
    print1(nums);

    int num = 5;
    print2(num);

    int *newNum = new int(10);
    print3(newNum);

    int *numsPtr = new int[3];
    numsPtr[0] = 10;
    numsPtr[1] = 11;
    numsPtr[2] = 12;
    print4(numsPtr);

    const int constNum = 7;
    print5(constNum);

    const int *constNumPtr = new int(8);
    //print6(constNumPtr); //can't pass to non const param

    float x{1.0};
    long lint{21};
    function(1,1);
    function(x,lint);
    //function(x,1);

    return 0;
}