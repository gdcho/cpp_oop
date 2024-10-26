#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class MyCustomClass {
private:
    string name = "";
public:

    MyCustomClass(string name) : name(name) {}

    void printStartThreadMessage() {
        //can access 'name' member variable
        cout << "Thread process started by thread on " << name << endl;
    }

    void printEndThreadMessage() {
        cout << "Thread finished executing" << endl;
    }

    //threads automatically call overloaded operator()
    void operator()() {
        printStartThreadMessage(); //can call other methods within operator()
        this_thread::sleep_for(chrono::seconds(2)); // Simulate I/O taking time
        printEndThreadMessage(); //can call other methods within operator()
    }
};

int main() {
    auto start_time = chrono::high_resolution_clock::now();
    cout << "Main thread started" << endl;

    // Create and launch threads using the functor
    MyCustomClass customClass1("My Class 1");
    MyCustomClass customClass2("My Class 2");

    // Both threads automatically call MyCustomClass' operator() and run immediately
    thread t1(customClass1);
    thread t2(customClass2);

    // Wait for threads to finish
    t1.join();
    t2.join();

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time);

    cout << "Main finished in " << duration.count() << " seconds" << endl; // Takes about 2 seconds

    return 0;
}