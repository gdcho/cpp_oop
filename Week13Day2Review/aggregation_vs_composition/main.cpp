#include <iostream>

using namespace std;

class Duck {
public:
};

class Fish {
};

class Pond {
    Duck* duckPtr; //HAS A relationship - Association

    Fish *fishPtr; //HAS A relationship - Association

    //PASSING IN pointer to Duck - Aggregation - empty diamond
    Pond(Duck* ptr) {
        duckPtr = ptr; //Aggregation.
    }
    Pond() {
        //CONSTRUCTING Fish inside of Pond - COMPOSITION - filled diamond
        fishPtr = new Fish(); //Composition.
    }
};

int main(){

}
