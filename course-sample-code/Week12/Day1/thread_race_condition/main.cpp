#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;

class FakeDatabase {
public:
    FakeDatabase() : value(0) {}

    void update(int name) {
        cout << "Thread " << name << ": starting update" << endl;
        int local_copy = value;
        cout << "Thread " << name << ": pre-increment - local_copy " << local_copy << ", FakeDatabase.value " << value << endl;
        local_copy += 1;
        cout << "Thread " << name << ": post-increment - local_copy " << local_copy << ", FakeDatabase.value " << value << endl;
        cout << "Thread " << name << ": sleep" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        value = local_copy;
        cout << "Thread " << name << ": assign to self.value - local_copy " << local_copy << ", FakeDatabase.value " << value << endl;
        cout << "Thread " << name << ": finishing update" << endl;
    }

    int getValue() {
        return value;
    }

private:
    int value;
};

int main() {
    FakeDatabase database;
    cout << "Testing update. Starting value is " << database.getValue() << "." << endl;

    // Create two threads
    // call the database's update function using threads and lambdas
    vector<thread> threads;
    for (int index = 1; index < 3; ++index) {
        threads.emplace_back([&database, index]() {
            database.update(index);
        });
    }

    // Join threads
    for (thread& t : threads) {
        t.join();
    }

    cout << "Testing update. Ending FakeDatabase value is " << database.getValue() << "." << endl;

    return 0;
}