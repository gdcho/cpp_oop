#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex swordMutex;
mutex shieldMutex;

using namespace std;

//function to acquire sword then shield
void equip1() {
    unique_lock<mutex> swordLock(swordMutex);
    this_thread::sleep_for(chrono::seconds(1)); // Simulate some processing time
    cout << "Soldier 1 acquired swordMutex, waiting for shieldMutex" << endl;

    unique_lock<mutex> shieldLock(shieldMutex); // Attempt to acquire shieldMutex
    cout << "Soldier 1 acquired shieldMutex" << endl;

    // Critical section of thread 1
    cout << "Soldier 1 equipped sword and shield mutexes" << endl;

    shieldLock.unlock();
    swordLock.unlock();
}

//function to acquire shield then sword
void equip2() {
    unique_lock<mutex> shieldLock(shieldMutex);
    this_thread::sleep_for(chrono::seconds(1)); // Simulate some processing time
    cout << "Soldier 2 acquired shieldMutex, waiting for swordMutex" << endl;

    unique_lock<mutex> swordLock(swordMutex); // Attempt to acquire swordMutex
    cout << "Soldier 2 acquired swordMutex" << endl;

    // Critical section of thread 2
    cout << "Soldier 2 equipped sword and shield mutexes" << endl;

    swordLock.unlock();
    shieldLock.unlock();
}

int main() {
    thread soldier1(equip1);
    thread soldier2(equip2);

    soldier1.join();
    soldier2.join();

    cout << "Program complete" << endl;

    return 0;
}
