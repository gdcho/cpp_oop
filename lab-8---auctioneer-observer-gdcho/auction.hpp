//
// Created by jyim3 on 2022-10-19.
//

#pragma once

#include "bidder.hpp"
#include "auctioneer.hpp"
#include <vector>
#include <string>

class Bidder;

/**
 * The Auction class is responsible for initializing the auction and
 * driving the auction till completion
 */
class Auction {
private:
    /**
     * The auctioneer object that is responsible for tracking the
     * highest bid and notifying the bidders if it changes
     */
    Auctioneer auctioneer;

public:

    /**
     * Constructor to initialize an auction
     * Requires a list of bidders that are attending the auction and can bid
     * @param bidders: vector of Bidder pointers
     */
    explicit Auction(const vector <Bidder *>& bidders);

    /**
     * Simulates the start the auction for the given item at the given starting price
     * Drives the auction till completion and prints the results
     * @param item: string, name of item
     * @param start_price: float, starting price of the item
     */
    void simulate_auction(const string& item, double start_price);
};
