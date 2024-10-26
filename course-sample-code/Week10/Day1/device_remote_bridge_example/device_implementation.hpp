//
// Created by A00257049 on 2020-11-04.
//

#ifndef DEVICE_REMOTE_BRIDGE_EXAMPLE_DEVICE_IMPLEMENTATION_HPP
#define DEVICE_REMOTE_BRIDGE_EXAMPLE_DEVICE_IMPLEMENTATION_HPP

#include <iostream>
#include <sstream>
using namespace std;

/*
    An interface for the Device dimension. This is the implementation
    layer that actually does all the work.
 */
struct IDevice {
    int volume = 50;
    string channel = "a_channel";
    bool enabled = true;

    IDevice(int volume, string channel, bool enabled) : volume(volume), channel(channel), enabled(enabled) {}

    virtual void enable() = 0;
    virtual void disable() = 0;
    virtual int get_volume() = 0;
    virtual void set_volume(int percent) = 0;
    virtual string get_channel() = 0;
    virtual void set_channel(string channel) = 0;
    virtual string get_string() const = 0;
    friend ostream& operator<<(ostream& os, const IDevice& id)
    {
        os << id.get_string();
        return os;
    }
};

/*
    A Radio Device. One of the possible devices (implementation) that
    can be matched to a remote.
 */
struct Radio : IDevice {
    Radio() : IDevice(50, "a_channel", true) {}

    void enable() { enabled = true; }
    void disable() { enabled = false; }
    int get_volume() {return volume;}
    void set_volume(int percent) {volume = percent;}
    string get_channel() {return channel;}
    void set_channel(string channel) {this->channel = channel;}
    string get_string () const
    {
        stringstream ss;
        ss << "Radio: " << boolalpha << enabled << ", " << volume << ", " << channel << endl;
        return ss.str();
    }
};

/*
    A TV Device. One of the possible devices (implementation) that
    can be matched to a remote.
 */
struct TV : IDevice {
    TV() : IDevice(50, "a_channel", true) {}

    void enable() { enabled = true; }
    void disable() { enabled = false; }
    int get_volume() {return volume;}
    void set_volume(int percent) {volume = percent;}
    string get_channel() {return channel;}
    void set_channel(string channel) {this->channel = channel;}
    string get_string () const
    {
        stringstream ss;
        ss << "TV: " << boolalpha << enabled << ", " << volume << ", " << channel << endl;
        return ss.str();
    }
};

#endif //DEVICE_REMOTE_BRIDGE_EXAMPLE_DEVICE_IMPLEMENTATION_HPP
