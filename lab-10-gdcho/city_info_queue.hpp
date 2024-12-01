//
// Created by jyim3 on 2023-08-16.
//

#ifndef LABSPACETEMPLATE_CITY_INFO_QUEUE_HPP
#define LABSPACETEMPLATE_CITY_INFO_QUEUE_HPP

#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include "city_info.hpp"

using namespace std;

/*
 * CityInfoQueue is a shared resource between Producers and Consumers. It contains a vector
 * of CityInfo (dataQueue)
 * It contains methods to
 *  - manage adding, removing, and checking on dataQueue
 *      - dataQueue must be protected by locks since Producers and Consumers access it
 *  - manage whether new data is still being added by producers
 *
 */
class CityInfoQueue {
public:
    /* default constructor with dataIncoming set to true */
    CityInfoQueue() { dataIncoming = true;}

    /* add new data to dataQueue */
    void put(const CityInfo cityInfo) {
        /* lock the mutex to protect dataQueue */
        lock_guard<mutex> lock(accessQueueMutex);
        /* add the element to the queue */
        dataQueue.push_back(cityInfo);
        cout << "Element has been added to the queue! Queue has " << dataQueue.size() << " elements" << endl << endl;
    }

    /* get and remove element from dataQueue */
    CityInfo get() {
        /* instantiate a CityInfo object */
        CityInfo cityInfo;
        /* lock the mutex to protect dataQueue */
        lock_guard<mutex> lock(accessQueueMutex);
        /* if the queue is not empty */
        if (!dataQueue.empty()) {
            /* get the first element in the queue */
            cityInfo = dataQueue.front();
            /* remove the first element in the queue */
            dataQueue.erase(dataQueue.begin());
        }
        cout << "Element has been removed from the queue! Queue has " << dataQueue.size() << " elements left" << endl;
        return cityInfo;
    }

    /* get the size of the queue */
    size_t size() const {
        std::lock_guard<std::mutex> lock(accessQueueMutex);
        return dataQueue.size();
    }

    /* check if the queue is empty */
    bool empty() const {
        std::lock_guard<std::mutex> lock(accessQueueMutex);
        return dataQueue.size() <= 0;
    }

    /* check if data is still incoming */
    bool isDataIncoming() {
        return dataIncoming;
    }

    /* set dataIncoming to boolean value based on input */
    bool setDataIncoming(bool data) {
        return dataIncoming = data;
    }

private:
    vector<CityInfo> dataQueue; //shared vector of CityInfos
    mutable std::mutex accessQueueMutex; //used to protect dataQueue
    bool dataIncoming; //boolean flag indicating if producers have finished gathering data
};

#endif //LABSPACETEMPLATE_CITY_INFO_QUEUE_HPP