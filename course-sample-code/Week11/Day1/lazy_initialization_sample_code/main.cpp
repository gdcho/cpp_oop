#include <iostream>
#include <Windows.h>
#include <unistd.h>

using namespace std;

//An expensive object that is computationally intensive.
struct Car {

    //Creating this object takes a while.
    Car() {
        cout << "Building a car. This is a time consuming process" << endl;
        sleep(2);
        cout << "Wait for it..." << endl;
        sleep(1);
        cout << "Car has been made" << endl;
    }

    friend ostream& operator<<(ostream& os, const Car& c) {
        return os << "I am an expensive car that uses a lot of resources" << endl;
    }
};

struct Client {
private:
    // The client has access to a car. In Lazy Inititalization we don't
    // initialize it outright.
    Car *car = nullptr;

public:

    Client() {
        //car = new Car; //normally instantiate all data members right away
    }

    /*
     *  When the car is accessed we check to see if it is initialized.
        If it isn't initialized then we initialize it and return it.
        This is lazy intialization. We have delayed the initialization
        of an expensive object until we needed it.
        :return: a Car
     */
    Car* getCar() {
        if(car == nullptr)
            car = new Car;
        return car;
    }

    ~Client(){
        delete car;
    }
};

int main() {
    Client client; //don't initialize the Car() inside client right away
    cout << *client.getCar() << endl; //initialize the Car() inside client only the first time .car is called
    cout << "End of program" << endl;
    return 0;
}