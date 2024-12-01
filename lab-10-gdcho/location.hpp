//
// Created by jyim3 on 2023-08-16.
//

#ifndef LABSPACETEMPLATE_LOCATION_HPP
#define LABSPACETEMPLATE_LOCATION_HPP

#include "iostream"

using namespace std;

/*
 * Latitude and longitude information representing a location in the world
 * No need to add code, but you may if needed
 */
struct Location {
    string latitude;
    string longitude;

    /* default constructor with parameters */
    Location(string latitute, string longitude) : latitude(latitute), longitude(longitude) {};

    /* print method */
    void print() {
        cout << " latitude: " << latitude;
        cout << " longitude: " << longitude;
        cout << endl;
    }
};

#endif //LABSPACETEMPLATE_LOCATION_HPP