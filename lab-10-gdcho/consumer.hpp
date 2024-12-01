//
// Created by jyim3 on 2023-08-16.
//

#ifndef LABSPACETEMPLATE_CONSUMER_HPP
#define LABSPACETEMPLATE_CONSUMER_HPP

#include <iostream>
#include <chrono>
#include <thread>
#include "city_info_queue.hpp"

using namespace std;

/*
 * Retrieves data from a shared CityInfoQueue
 */
class Consumer {
public:
    /*
     * Constructor
     * @param q shared CityInfoQueue
     */
    Consumer(CityInfoQueue& q) : queue(q), id(increment_id()) {}

    /*
     * Code in this overloaded operator will be executed by threads
     */
    void operator()() {
        /*
         * Consumers stays in a loop while more data is incoming or the queue is not empty
         *  Gets CityInfo from CityInfoQueue if the queue is not empty
         *  - prints the retrieved CityInfo, then sleeps for some time
         *  Consumers sleeps for some time if the queue is empty
         */
        while (queue.isDataIncoming() || !queue.empty()) {
            /* if the queue is not empty */
            if (!queue.empty()) {
                cout << "Consumer " << id << " is consuming from the queue" << endl;
                /* get the city info from the queue */
                CityInfo cityInfo = queue.get();
                /* print the city info */
                cityInfo.print();
                /* sleep for 500 milliseconds */
                this_thread::sleep_for(chrono::milliseconds(500));
            } else {
                cout << "Consumer " << id << " is sleeping since queue is empty" << endl;
                /* sleep for 750 milliseconds */
                this_thread::sleep_for(chrono::milliseconds(750));
            }
        }
    }

private:
    static int staticId;
    static int increment_id() {
        return ++staticId;
    }

    CityInfoQueue& queue;
    int id;
};
int Consumer::staticId = 0;
#endif //LABSPACETEMPLATE_CONSUMER_HPP