#include <iostream>
#include "device_implementation.hpp"
#include "remote_abstraction.hpp"

/*
Demonstrates the Bridge Pattern. An entity with two independent
dimensions - a Remote (Abstraction, Control layer) and a
Device (Implementation) is decoupled into two separate hierarchies.
These are then "bridged" using composition. Refer to the bridge_uml.png
diagram while reading this code.
 */

int main() {
//combination 1: TV Remote
    cout << "---- COMBO 1: TV Remote ----" << endl;
    TV *tv = new TV;
    Remote *my_remote = new Remote(tv);
    cout << *(my_remote->device) << endl;
    my_remote->change_channel("Cartoon Network");
    cout << "After change channel - " << *(my_remote->device) << endl;
    my_remote->toggle_power();
    cout << "After toggle power - " << *(my_remote->device) << endl;
    cout << endl;

    //combination 2 - Use same remote to point at radio
    cout << "---- COMBO 2: Same remote can control radio ----" << endl;

    Radio *radio = new Radio;
    my_remote->device = radio;
    cout << *(my_remote->device) << endl;
    my_remote->change_channel("95.3 FM");
    cout << "After change channel: " << *(my_remote->device) << endl;
    cout << endl;

    //combination 3: Advanced Radio Remote
    cout << "---- COMBO 3: Advanced Radio Remote ----" << endl;
    //create new advanced remote to point at radio
    delete my_remote; //delete remote before my_remote points to AdvancedRemote
    my_remote = new AdvancedRemote(radio);
    cout << *(my_remote->device) << endl;
    ((AdvancedRemote *)my_remote)->mute();
    cout << "After mute - " << *(my_remote->device) << endl;
    my_remote->toggle_power();
    cout << "After toggle power - " << *(my_remote->device) << endl;

    delete tv;
    delete radio;
    delete my_remote;
    return 0;
}