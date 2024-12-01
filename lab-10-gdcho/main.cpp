//Name: David Cho
//Student# : A01351217

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <thread>
#include "producer.hpp"
#include "consumer.hpp"

#include "location.hpp"

using namespace std;

/**
 * Reads location data from a file and returns a vector of Location objects
 * @param filePath path to the file containing location data
 * @return vector of Location objects
 */
vector<Location> readLocationsFromFile(const string &filePath) {
    /* instantiate a vector of Location objects */
    vector<Location> locations;
    /* open the file */
    ifstream inputFile(filePath);

    /* check if the file is open */
    if (!inputFile.is_open()) {
        cerr << "Unable to open file: " << filePath << endl;
        exit(-1);
    }

    /* instantiate variables to store latitude and longitude */
    string latitude, longitude;
    /* instantiate a string to store each line of the file */
    string line;

    /* while there are lines to read from the file */
    while (getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }

        /* instantiate an istringstream object to read the line */
        istringstream iss(line);
        /* instantiate a string to store each token */
        string temp;
        /* instantiate a vector of strings to store the tokens */
        vector<string> tokens;

        /* while there are tokens to read from the line */
        while (getline(iss, temp, '\t')) {
            tokens.push_back(temp);
        }

        /* if there are at least 2 tokens */
        if (tokens.size() >= 2) {
            /* store the latitude and longitude */
            latitude = to_string(stod(tokens[0]));
            longitude = to_string(stod(tokens[1]));

            /* add the location to the vector */
            locations.emplace_back(latitude, longitude);
        } else {
            cerr << "Error reading location data from file." << endl;
            exit(-1);
        }
    }
    /* close the file */
    inputFile.close();
    /* return the vector of Location objects */
    return locations;
}

/**
 * Main function to test the Producer-Consumer pattern with implementation
 * of threads and concurrent access to shared resources
 * @return 0
 */
int main() {
    /* read latitude and longitude data from locations.txt or locations_test.txt */
    vector<Location> locations = readLocationsFromFile("../locations_test.txt");

    /* instantiate the shared CityInfoQueue used by producers and consumers */
    CityInfoQueue cityInfoQueue;

    /* create X number of producers
     pass in a portion of the list of locations
     pass in shared CityInfoQueue */
    /* create 3 producers */
    const int NUM_PRODUCERS = 3;
    /* calculate the number of locations each producer will handle */
    const int LOCATIONS_PER_PRODUCER = locations.size() / NUM_PRODUCERS;

    /* instantiate a vector of Producer objects */
    vector<Producer> producers;
    /* for each producer */
    for (int i = 0; i < NUM_PRODUCERS; ++i) {
        /* calculate the range of locations for the producer */
        auto begin = locations.begin() + i * LOCATIONS_PER_PRODUCER;
        /* if it is the last producer, set the end to the end of the locations vector */
        auto end = (i == NUM_PRODUCERS - 1)
                   ? locations.end()
                   : locations.begin() + (i + 1) * LOCATIONS_PER_PRODUCER;
        /* add the producer to the vector */
        producers.emplace_back(vector<Location>(begin, end), cityInfoQueue);
    }

    /* create Y number of consumers
     pass in shared CityInfoQueue */
    /* create 2 consumers */
    const int NUM_CONSUMERS = 2;
    /* instantiate a vector of Consumer objects */
    vector<Consumer> consumersVec;
    /* for each consumer */
    for (int i = 0; i < NUM_CONSUMERS; ++i) {
        /* add the consumer to the vector */
        Consumer consumer(cityInfoQueue);
        consumersVec.emplace_back(consumer);
    }

    /* start producer and consumer threads */
    /* instantiate vectors of threads for producers and consumers */
    vector<thread> producerThreads;
    /* reserve space for the producer threads */
    producerThreads.reserve(producers.size());
    /* for each producer */
    for (auto &producer: producers) {
        /* add the producer thread to the vector */
        producerThreads.emplace_back(thread(producer));
    }

    /* instantiate vectors of threads for consumers */
    vector<thread> consumerThreads;
    /* reserve space for the consumer threads */
    consumerThreads.reserve(consumersVec.size());
    /* for each consumer */
    for (auto &consumer: consumersVec) {
        /* add the consumer thread to the vector */
        consumerThreads.emplace_back(thread(consumer));
    }

    /* wait for producers to finish fetching data */
    for (auto &thread: producerThreads) {
        /* wait for the thread to finish */
        thread.join();
    }

    /* producers have finished fetching data now. Tell the CityInfoQueue that no more data will be added */
    cityInfoQueue.setDataIncoming(false);

    /* wait for consumers to finish consuming data */
    for (auto &thread: consumerThreads) {
        /* wait for the thread to finish */
        thread.join();
    }

    return 0;
}