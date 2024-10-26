#include <iostream>
#include <vector>
using namespace std;

class MyInnerClass {
public:
    ~MyInnerClass() {
        cout << "MyInnerClass destructor" << endl;
    }
};

////class with static memory
//class MyClass {
//public:
//    vector <MyInnerClass> vectorMics;
//    MyClass() {
//        vectorMics.reserve(3);
//        vectorMics.push_back(MyInnerClass{});
//        vectorMics.push_back(MyInnerClass{});
//        vectorMics.push_back(MyInnerClass{});
//    }
//    ~MyClass() {
//        cout << "Destroying MyClass" << endl;
//    }
//};

//class with dynamic memory
class MyClass {
public:
    vector <MyInnerClass*> vectorMics;
    MyClass() {
        vectorMics.reserve(3);
        vectorMics.push_back(new MyInnerClass{});
        vectorMics.push_back(new MyInnerClass{});
        vectorMics.push_back(new MyInnerClass{});
    }
    ~MyClass() {
        cout << "Destroying MyClass" << endl;
        for(MyInnerClass *mic : vectorMics) {
            delete mic;
        }
        vectorMics.clear();
    }
};

MyClass *createMyClass() {
    return new MyClass;
}

int main() {
    MyClass mc1;

    //MyClass *mc2 = new MyClass;
    //MyClass *mc2 = createMyClass();
    //delete mc2;
    return 0;
}