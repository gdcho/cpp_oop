#include <iostream>
#include <vector>

using namespace std;

void print(vector<string> v)
{
    for(auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<string> v ={"a","b","c","d","e","f"};
    print(v);
    //vector<string>::iterator
    auto nearEndIt = (v.end() - 1); //get new iterator from iterator subtraction

    cout << "v.begin(): " << *(v.begin()) << endl;
    cout << "++v.begin(): " <<  *(++v.begin()) << endl; //pre-increment iterator
    cout << "v.begin() + 3: " <<  *(v.begin() + 3) << endl; //move iterator with +
    cout << "v.end() - 1: " << *nearEndIt << endl;
    cout << "v.end() - nearEndIt: " << v.end() - nearEndIt << endl; //subtract iterators to get difference_type

    cout << ((nearEndIt < v.end()) ? "TRUE" : "FALSE") << endl;

    vector<string>::iterator midIt = v.begin()+3;
    *midIt = "z"; //same as v[3] = "z";
    print(v);

    //show iterators are not pointers, can't print out iterator directly
    string *ptr = new string{"a"};

    cout << "deference ptr: " << *ptr << endl;
    cout << "address of ptr:  " << &ptr << endl;
    cout << "value of ptr: " << ptr << endl;

    cout << endl;
    cout << "address of iterator: " << &midIt << endl;
    cout << "dereference iterator: " << *midIt << endl;
    //cout << midIt << endl; //error can't print out iterator why? because iterator is not a pointer




    return 0;
}