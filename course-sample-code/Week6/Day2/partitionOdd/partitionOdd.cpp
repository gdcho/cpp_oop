// partition algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::partition
#include <vector>       // std::vector

bool IsOdd (int i)
{
    return (i%2)==1;
}

using namespace std;
int main () {
    vector<int> myvector;

    // set some values:
    for (int i=1; i<11; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9 10

    vector<int>::iterator iterBound;
    iterBound = partition (myvector.begin(), myvector.end(), IsOdd); //call partition algorithm

    // print out content:
    cout << "odd elements:";
    for (auto it=myvector.begin(); it!=iterBound; ++it)
        cout << ' ' << *it;
    cout << '\n';

    cout << "even elements:";
    for (auto it=iterBound; it!=myvector.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    return 0;
}