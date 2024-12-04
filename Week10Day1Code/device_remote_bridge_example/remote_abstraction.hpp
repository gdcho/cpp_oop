//
// Created by A00257049 on 2020-11-04.
//

#ifndef DEVICE_REMOTE_BRIDGE_EXAMPLE_REMOTE_ABSTRACTION_HPP
#define DEVICE_REMOTE_BRIDGE_EXAMPLE_REMOTE_ABSTRACTION_HPP

#include "device_implementation.hpp"

/*
    The Remote class represents the Abstraction dimension (this doesn't
    have to be an ABC and may have child classes, not necessarily). In
    this case the Remote class sort of acts like a wrapper but this
    isn't mandatory. Depending on the needs of the system the
    implementation (e.g. IDevice) that this class is composed of can be
    used however it is needed.
 */
struct Remote {
    IDevice* device; //bridge to access the device

    Remote(IDevice *d) {
        device = d;
    }

    void toggle_power() {
        if (device->enabled)
            device->disable();
        else
            device->enable();
    }

    void volume_up() {
        device->set_volume(device->get_volume() * 1.1);
    }

    void volume_down() {
        device->set_volume(device->get_volume()*0.9);
    }

    void change_channel(string new_channel) {
        device->set_channel(new_channel);
    }
};

/*
    A child of the Remote class. This is an example of how the
    abstraction dimension can have its own inheritance hierarchy
    independent of the implementation class. We only need to add a
    single class to allow for multiple combinations.
 */
struct AdvancedRemote : Remote {
    AdvancedRemote(IDevice *d) : Remote(d) {}

    void mute() {
        device->set_volume(0);
    }
};

#endif //DEVICE_REMOTE_BRIDGE_EXAMPLE_REMOTE_ABSTRACTION_HPP
