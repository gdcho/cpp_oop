#include <iostream>
#include <set>
#include <iterator>
#include <map>

using namespace std;
int main()
{
    multiset<int> mymultiset;
    multiset<int>::iterator it;

    // insert some values:
    mymultiset.insert (40);                           // 40
    for (int i=1; i<7; i++)
    {
        mymultiset.insert(i*10);                      // 10 20 30 40 40 50 60
    }

    it=mymultiset.begin();                            // point iterator to beginning
    it++;                                             // increment iterator to point to beginning + 1. point at value 20

    mymultiset.erase (it);                            // 10 30 40 40 50 60

    mymultiset.erase (40);                            // 10 30 50 60  //erased all 40s!

    it=mymultiset.find (50);                          // points it at 50

    mymultiset.erase ( it, mymultiset.end() );        // erases starting at it till end
                                                      // 10 30

    cout << "mymultiset contains:";
    for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    return 0;

}