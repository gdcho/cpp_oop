#include <iostream>
#include <vector>
using namespace std;

// How are dynamic classes used and constructed.
// What cases should they be used rather than static classes?

// 1. How are classes with dynamic memory data members used and constructed.
// What cases should they be used rather than static classes?

// 2. How are classes created with dynamic memory used and constructed.
// What cases should they be used rather than static classes?

class MyInnerClass {
public:
    ~MyInnerClass() {
        cout << "Destroying MyInnerClass" << endl;
    }
};

class MyClass {
public:
    vector <MyInnerClass*> vectorMics;
    MyClass() {
        vectorMics.reserve(3);
        vectorMics.push_back(new MyInnerClass{});
        vectorMics.push_back(new MyInnerClass{});
        vectorMics.push_back(new MyInnerClass{});
    }

    MyClass(const MyClass& other) {
        cout << "Copy MyClass" << endl;
        for(int i=0; i<3; i++)
        {
            vectorMics.push_back(new MyInnerClass);
        }
    }

    ~MyClass() {
        cout << "Destroying MyClass" << endl;
        for(MyInnerClass *mic : vectorMics) {
            delete mic;
        }
        vectorMics.clear();
    }
};

MyClass createMyClass() {
    return MyClass{};
}

MyClass *createMyClassDynamic() {
    return new MyClass{};
}


int main() {
    //static allocation
    vector<MyClass>v;
    v.reserve(1);
    v.push_back(createMyClass());

//    vector<MyClass*>v2;
//    v2.reserve(1);
//    v2.push_back(createMyClassDynamic());
//    for(MyClass* mc : v2)
//    {
//        delete mc;
//    }

    cout << "End Main" << endl;
}