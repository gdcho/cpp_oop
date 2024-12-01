#include <iostream>

using std::cout;
using std::endl;

void change(const int * pt, int n);

int main()
{
    int num1 = 100; //originally declared as int. VALID to cast away const-ness in the future
    const int num2 = 200; //originally declared as const int. INVALID to cast away const-ness in the future

    cout << "num1: " << num1 << ", num2: " << num2 << endl;
    change(&num1, -50);
    change(&num2, -50);
    cout << "num1: " << num1 << ", num2: " << num2 << endl;
    return 0;
}

void change(const int * pt, int n)
{
    cout << "---Inside function" << endl;
    int * pNum;
  
    // We said the parameter is const
    // Let's cast that const-ness away
    pNum = const_cast<int *>(pt);
    *pNum += n; // Does this work?
    cout << *pNum << endl; //output inside function?
    cout << "---leaving function" << endl;
}
