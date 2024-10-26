#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

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

    const int NUM_THREADS = 2;
    vector<thread> threads;
    for(int i=0; i<NUM_THREADS; i++) {
        //notice how we construct the MyCustomClass object directly into the threads vector using emplace_back
        threads.emplace_back(MyCustomClass("My Class " + to_string(i)));
    }

    for(int i=0; i<NUM_THREADS; i++) {
        threads[i].join();
    }

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time);

    cout << "Main finished in " << duration.count() << " seconds" << endl; // Takes about 2 seconds

    return 0;
}