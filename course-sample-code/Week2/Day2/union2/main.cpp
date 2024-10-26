#include <iostream>

using namespace std;

const int SHORT_TYPE = 0;
const int INT_TYPE = 1;
const int LONG_TYPE = 2;

union integralUnion{
    short short_value;
    int int_value;
    long long_value;
};

struct integrals {
    int type;
    integralUnion iu;

    integrals(int t)
    {
        type = t;
        iu.short_value = 0;
        iu.int_value = 0;
        iu.long_value = 0;
    }

    void setValue(int num)
    {
        switch(type)
        {
            case SHORT_TYPE:
                iu.short_value = num;
                break;
            case INT_TYPE:
                iu.int_value = num;
                break;
            case LONG_TYPE:
                iu.long_value = num;
                break;
        }
    }

    void print() {
        switch (type) {
            case SHORT_TYPE:
                cout << "SHORT_TYPE: " << iu.short_value << endl;
                break;
            case INT_TYPE:
                cout << "INT_TYPE: " << iu.int_value << endl;
                break;
            case LONG_TYPE:
                cout << "LONG_TYPE: " << iu.long_value << endl;
                break;
        }
    }
};

int main() {
    integrals ints{INT_TYPE};
    ints.setValue(5);
    ints.print();

    integrals shorts{SHORT_TYPE};
    shorts.setValue(7);
    shorts.print();

    integrals longs{LONG_TYPE};
    longs.setValue(22);
    longs.print();
    return 0;
}