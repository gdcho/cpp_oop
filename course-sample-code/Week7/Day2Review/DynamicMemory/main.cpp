#include <iostream>
using namespace std;

struct operation {
    virtual int perform(int x, int y) = 0;
    virtual ~operation(){}
};

struct subtraction : operation {
    int perform(int x, int y)
    {
        return x - y;
    }
};

struct addition : operation{
    int perform(int x, int y)
    {
        return x + y;
    }
};

operation *getOperation(char c) {
    if(c == '+')
        return new addition();
    if(c == '-')
        return new subtraction();
    return nullptr;
}

int doOperation(operation * op, int x, int y)
{
    return op->perform(x,y);
}

int main() {
    operation* add = getOperation('+'); //create dynamic memory in getOperation
    cout << doOperation(add, 10, 5) << endl; //use that memory elsewhere in doOperation

    operation* subtract = getOperation('-');
    cout << doOperation(subtract, 10, 5) << endl;

    delete add;
    delete subtract;
    return 0;
}