//
// Created by jyim3 on 2022-10-19.
//

#pragma once

#include <iostream>
#include <random>

using namespace std;

/* forward declaration */
class Auctioneer;

/**
 * The Bidder class is responsible for initializing the bidder
 * and updating the bidder when the auctioneer notifies them
 */
class Bidder {
    /* name of the bidder */
    string name;
    /* budget of the bidder */
    double budget;
    /* probability of the bidder bidding */
    double bid_probability;
    /* percentage increase in bid */
    double bid_increase_perc;
    /* highest bid */
    double highest_bid;

public:
    /**
     * Constructor to initialize the bidder
     * @param name: string, name of the bidder
     * @param budget: float, budget of the bidder
     * @param bid_probability: float, probability of the bidder bidding
     * @param bid_increase_perc: float, percentage increase in bid
     */
    Bidder(string name, double budget, double bid_probability, double bid_increase_perc)
             : name(name), budget(budget), bid_probability(bid_probability), bid_increase_perc(bid_increase_perc) {}

    /**
     * Update is called by the auctioneer when they need to notify
     * @param auctioneer pointer to the auctioneer object
     */
    void update(Auctioneer * auctioneer);

    /**
     * Destructor to delete the bidder
     */
    ~Bidder() = default;

    /**
     * Getter for the highest bid
     * @return string, the highest bid
     */
    inline double get_highest_bid() { return highest_bid; }

    /**
     * Getter for the name of the bidder
     * @return string, the name of the bidder
     */
    inline string get_name() { return name; }

    /**
     * Overloaded << operator to print the bidder
     * @param os: ostream object
     * @param bidder: Bidder object
     * @return ostream object
     */
    friend ostream & operator<<(ostream & os, const Bidder & bidder) {
        os << bidder.name;
        return os;
    }
};

