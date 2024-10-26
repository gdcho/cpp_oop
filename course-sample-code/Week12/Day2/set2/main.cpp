#include <iostream>
#include <set>
#include <iterator>

using namespace std;

template <typename T = string, int N = 25>
class MySet{
    T set [N];
public:
    void set_member(int index, T member);
    T get_member(int index) {return set[index];}
};

template <typename T, int N>
void MySet<T, N>::set_member(int index, T member)
{
    set[index] = member;
}

int main()
{
    MySet<int, 10> myInts;
    myInts.set_member(0,5);
    myInts.set_member(1,99);

    MySet<> myStrings;
    myStrings.set_member(0,"Hello");
    myStrings.set_member(1,"World");

    cout << myInts.get_member(0) << endl;
    cout << myInts.get_member(1) << endl;

    cout << myStrings.get_member(0) << endl;
    cout << myStrings.get_member(1) << endl;

    return 0;

}