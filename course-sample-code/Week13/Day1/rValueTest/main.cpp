#include <iostream>

struct test {
    int num =99;
    int getNum() {
        return 5;
    }
    int *getNumPtr() {
        return new int(5);
    }
};

int main() {
    int one = 1;
    int a[] = {1,1,1};
    test t;
    int &&r = t.getNum();
    int *&&rPtr = t.getNumPtr();
    int &&num = one++;

    return 0;
}