#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex swordMutex;
mutex shieldMutex;

using namespace std;

//function to acquire sword then shield
void equip1() {
    while(true){
        unique_lock<mutex> swordLock(swordMutex);
        cout << "Soldier 1 acquired swordLock, sleep for a bit" << endl;
        this_thread::sleep_for(chrono::milliseconds(100)); // Introduce a small delay

        unique_lock<mutex> shieldLock(shieldMutex, defer_lock); //defer_lock means, don't try to lock right away. Must call try_lock() to attempt to lock
        cout << "Soldier 1 trying to get shieldLock" << endl;
        if (shieldLock.try_lock()) {
            // Critical section: Both mutexes acquired successfully
            cout << "Soldier 1 acquired shieldLock too! GOT BOTH SWORD AND SHIELD!" << endl;
            cout << "Soldier 1 releasing both sword and shieldLock!" << endl;
            shieldLock.unlock();
            swordLock.unlock();
            break; // Exit the loop
        } else {
            // Release swordLock temporarily
            cout << "Soldier 1 couldn't get shieldLock too" << endl;
            cout << "Soldier 1 releasing swordLock temporarily" << endl;
            swordLock.unlock();
            this_thread::sleep_for(chrono::milliseconds(1000)); // Wait a bit before retrying
        }

    }
}

//function to acquire shield then sword
void equip2() {
    while(true) {
        unique_lock<mutex> shieldLock(shieldMutex);
        cout << "Soldier 2 acquired shieldLock, sleep for a bit" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000)); // Introduce a small delay

        unique_lock<mutex> swordLock(swordMutex, defer_lock); //defer_lock means, don't try to lock right away. Must call try_lock() to attempt to lock
        cout << "Soldier 2 trying to get swordLock" << endl;
        if (swordLock.try_lock()) {
            // // Critical section: Both mutexes acquired successfully
            cout << "Soldier 2 acquired swordLock too! GOT BOTH SWORD AND SHIELD!" << endl;
            cout << "Soldier 2 releasing both sword and shieldLock!" << endl;
            swordLock.unlock();
            shieldLock.unlock();
            break; // Exit the loop
        } else {
            // Release shieldLock temporarily
            cout << "Soldier 2 couldn't get swordLock too" << endl;
            cout << "Soldier 2 releasing shieldLock temporarily" << endl;
            shieldLock.unlock();
            this_thread::sleep_for(chrono::milliseconds(1000)); // Wait a bit before retrying
        }
    }
}

int main() {
    thread soldier1(equip1);
    thread soldier2(equip2);

    soldier1.join();
    soldier2.join();

    cout << "Program complete" << endl;

    return 0;
}
