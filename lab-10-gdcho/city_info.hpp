//
// Created by jyim3 on 2023-08-16.
//

#ifndef LABSPACETEMPLATE_CITY_INFO_HPP
#define LABSPACETEMPLATE_CITY_INFO_HPP

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

/*
 * Expanded information representing information about a city
 * No need to add code, but you may if needed
 */
class CityInfo {
public:
    string latitude;
    string longitude;
    string timezoneId;
    int offset;
    string countryCode;
    string mapUrl;

    /* default constructor */
    CityInfo() {}

    /* constructor with parameters */
    CityInfo(string latitude, string longitude, string timezoneId, int offset, string countryCode, string mapUrl) :
            latitude(latitude),
            longitude(longitude),
            timezoneId(timezoneId),
            offset(offset),
            countryCode(countryCode),
            mapUrl(mapUrl)
    {}

    /* print method */
    void print() {
        cout << "latitude: " << latitude << endl;
        cout << "longitude: " << longitude << endl;
        cout << "timezoneId: " << timezoneId << endl;
        cout << "offset: " << offset << endl;
        cout << "countryCode: " << countryCode << endl;
        cout << "mapURL: " << mapUrl << endl << endl;
    }
};

#endif //LABSPACETEMPLATE_CITY_INFO_HPP