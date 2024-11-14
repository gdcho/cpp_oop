//
// Created by jyim3 on 2022-10-19.
//

#pragma once

#include <vector>
#include "bidder.hpp"

using namespace std;

double const ZERO = 0;

/**
 * The Auctioneer class is responsible for tracking the highest bid
 * and notifying the bidders if it changes
 */
class Auctioneer {
    /* list of bidders */
    vector <Bidder *> bidders;
    /* highest bid */
    double highest_bid = ZERO;
    /* highest bidder */
    Bidder *highest_bidder = nullptr;
    /* flag to check if it is the first bid */
    bool is_first_bid = true;

public:
    /**
     * Constructor to initialize the auctioneer
     */
    Auctioneer() = default;

    /**
     * Adds a bidder to the list of tracked bidders
     * @param bidder: object with __call__(auctioneer) interface
     */
    void register_bidder(Bidder * bidder);

    /**
     * Resets the auctioneer. Removes all the bidders
     * and resets the highest bid to 0
     */
    void reset_auctioneer();

    /**
     * Executes all the bidder callbacks. Should only be called if the
     * highest bid has changed
     */
    void notify_bidders();

    /**
     * Accepts a new bid and updates the highest bid. This notifies all
     * the bidders via their callbacks
     * @param bid: a double, the bid
     * @param bidder: The bidder that placed the bid
     */
    void accept_bid(double bid, Bidder *bidder = nullptr);

    /**
     * Get the list of bidders
     * @return vector of Bidder pointers
     */
    inline vector<Bidder *> get_bidders() { return bidders; }

    /**
     * Get the highest bidder
     * @return Bidder pointer
     */
    inline Bidder * get_highest_bidder() { return highest_bidder; }

    /**
     * Get the highest bid
     * @return double
     */
    inline double get_highest_bid() { return highest_bid; }

    /**
     * Get the flag to check if it is the first bid
     * @return bool
     */
    inline bool get_is_first_bid() { return is_first_bid; }
};



