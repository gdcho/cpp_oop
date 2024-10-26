#include <iostream>
using namespace std;

//int createStaticNum(int num)
//{
//    int n = num; //statically allocate num to n
//    return n;
//}

int* createStaticNum(int num)
{
    int n = num; //statically allocate num to n
    return &n;
}

int* createDynamicNum(int num)
{
    int *n = new int(num); //create an integer in the scope of createNum
    return n;
}

int* modifyNum(int *num)
{
    (*num)++;
    return num;
}

int main() {
    //int *myNum = createDynamicNum(5); //memory created in createNum
    int *myNum = createStaticNum(5); //statically allocated n disappears

    myNum = modifyNum(myNum); //passed into another function and modified
    cout << *myNum; //brought back to main and printed

    delete myNum;
    return 0;
}