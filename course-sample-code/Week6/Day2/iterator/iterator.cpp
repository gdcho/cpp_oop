#include <iostream>
#include <list> //bidirectional iterator
#include <forward_list>
#include <vector>

using namespace std;
int main() {
    forward_list <int> forward = {1,2,3,4,5};
    forward_list <int>::iterator fi = forward.begin(); //forward iterator
//
    cout << *fi << endl;
    fi++; //points at 2
    cout << *fi << endl;
//    //fi--; //can't decrement forward iterator

    list <int> container = {1,2,3,4,5};
    list <int>::iterator itBegin = container.begin(); //birectional iterator
    list <int>::iterator itEnd = container.end(); //bidirectional iterator

    *itBegin = 999; //assign using iterator (read and write)
    cout << "first: " << *itBegin << endl;
    // itBegin += 5; // cannot do this with list iterator only random access iterator

    for(auto i = container.begin(); i != container.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;

//    itBegin is pointing to first element
//    it is pointing at 999
//    after assignment, itBegin++ happens
//    itBegin points at next element, which is 2
    list <int>::iterator it = itBegin++; //makes a copy of current iterator then moves to next position

//    list <int>::iterator it = itBegin;
//    itBegin++;

    //it is pointing to first element
    //itBegin is pointing to second element
    cout << "*it: " << *it << endl;
    cout << "*itBegin: " << *itBegin << endl;
    return 0;
}