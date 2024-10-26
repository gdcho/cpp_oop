#include <iostream>
#include <vector>

using namespace std;

//copy constructor usage in enhanced for loops ...ex: for (User& user: users)

class MyClass {
public:
    MyClass() = default;

    MyClass(const MyClass& other)
    {
        cout << "Copy constructor" << endl;
    }
};

int main() {
    const int CAPACITY = 3;
    vector<MyClass> my_classes;

    my_classes.reserve(CAPACITY);
    cout << "my_classes.size(): " << my_classes.size() << endl;
    cout << "my_classes.capacity(): " << my_classes.capacity() << endl;

    cout << "Adding my classes to vector" << endl;
    for (int i=0; i<CAPACITY; i++) {
        cout << "Pushing to vector" << endl;
        MyClass m;
        my_classes.push_back(m);
        cout << "my_classes.size(): " << my_classes.size() << endl;
        cout << "my_classes.capacity(): " << my_classes.capacity() << endl;
    }

    cout << endl << "Iterating through vector - classic" << endl;
    for (int i=0; i<my_classes.size(); i++)
    {
        MyClass m = my_classes[i];
        cout << "classic " << i << endl;
    }

    cout << endl << "Iterating through vector - classic with reference" << endl;
    for (int i=0; i<my_classes.size(); i++)
    {
        MyClass &m = my_classes[i];
        cout << "classic with reference " << i << endl;
    }

    cout << endl << "Iterating through vector - classic for each" << endl;
    for (MyClass m : my_classes)
    {
        cout << "classic for each" << endl;
    }

    cout << endl << "Iterating through vector - reference for each" << endl;
    for (MyClass &m : my_classes)
    {
        cout << "reference for each" << endl;
    }

    cout << endl << "Iterating through vector - pointer" << endl;
    for (int i=0; i<my_classes.size(); i++)
    {
        MyClass *m = &my_classes[i];
        cout << "pointer " << i  << m << endl;
    }

    cout << endl << "Iterating through vector - iterator" << endl;
    for (auto iter = my_classes.begin(); iter != my_classes.end(); ++iter)
    {
        cout << "iter " << endl;
    }

    return 0;
}