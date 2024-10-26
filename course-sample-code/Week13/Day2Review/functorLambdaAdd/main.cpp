#include <iostream>
#include <algorithm>
#include <vector>
//https://www.geeksforgeeks.org/functors-in-cpp/

using namespace std;

//adds 1 to parameter
int incrementFunc(int x) {
    return (x+1);
}

// A Functor
class increment
{
private:
    int add;
public:
    increment(int n) : add(n) {  }

    // This operator overloading enables calling
    // operator function () on objects of increment
    int operator () (int arr_num) const {
        return add + arr_num;
    }
};

void print(vector <int> &v)
{
    for (int i : v)
        cout << i << " ";
}
// Driver code
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v2 = v;
    vector<int> v3 = v;
    int add = 5;

    //call algorithm to apply incrementFunc to elements in array
    //problem: can't dynamically change amount to increment. Need to write new functions
    transform(v.begin(), v.end(), v.begin(), incrementFunc);

    //functor version : call algorithm to apply increment functor with custom add to elements in array
    transform(v2.begin(), v2.end(), v2.begin(), increment(add));

    //lambda version : call algorithm to apply lambda with custom add to element in array
    transform(v3.begin(), v3.end(), v3.begin(), [add](int arr_num)
    {
        return add + arr_num;
    });

    cout << "transform with function: ";
    print(v);
    cout << endl << "transform with functor: ";
    print(v2);
    cout << endl << "transform with lambda: ";
    print(v3);
}