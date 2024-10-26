#include <iostream>
#include <vector>

using namespace std;
int main() {
    vector <int> v;
    cout << "v.size(): " << v.size() << endl;
    v.push_back(5);
    cout << "v.size(): " << v.size() << endl;
    v.push_back(6);
    v.push_back(7);

    cout << "v.size(): " << v.size() << endl; //number of elements in vector
    cout << "v.capacity(): " << v.capacity() << endl; //how much total space vector has
    for(int val : v)
    {
        cout << val << " ";
    }
    return 0;
}