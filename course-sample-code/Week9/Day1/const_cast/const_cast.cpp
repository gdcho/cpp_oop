#include <iostream>

using std::cout;
using std::endl;

void change(const int * pt, int n);

int main()
{
    int num1 = 100;
    const int num2 = 200;

    cout << "num1: " << num1 << ", num2: " << num2 << endl;
    change(&num1, -50);
    change(&num2, -50);
    cout << "num1: " << num1 << ", num2: " << num2 << endl;
    return 0;
}

void change(const int *pt, int n)
{
    int * pNum;
  
    // We said the parameter is const
    // Let's cast that const-ness away
    pNum = const_cast<int *>(pt);
    *pNum += n; // Does this work?
    cout << *pNum << endl; //output inside function?
 
}
