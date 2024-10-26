//
// Created by A00257049 on 2020-10-14.
//

#ifndef QUICKQUESTIONS_MYCLASS_HPP
#define QUICKQUESTIONS_MYCLASS_HPP

struct MyClass {
    int x = 1232;
    int y = 7676;

    MyClass(int x, int y);
    int getX() { return x; }
    void complicatedFunction();
};

class MyClass1 {
private:
    int x = 0;
    friend void friendFunc(MyClass1);
};

#endif //QUICKQUESTIONS_MYCLASS_HPP
