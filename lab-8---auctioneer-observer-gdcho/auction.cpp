//
// Created by jyim3 on 2022-10-19.
//

#include "auction.hpp"

/**
 * Constructor to initialize an auction
 * Requires a list of bidders that are attending the auction and can bid
 * @param bidders: vector of Bidder pointers
 */
Auction::Auction(const vector<Bidder *> & bidders) : auctioneer() {
    for (Bidder * bidder: bidders) {
        auctioneer.register_bidder(bidder);
    }
}

/**
 * Simulates the start the auction for the given item at the given starting price
 * Drives the auction till completion and prints the results
 * @param item: string, name of item
 * @param start_price: float, starting price of the item
 */
void Auction::simulate_auction(const string & item, double start_price) {
    /* start the auction */
    cout << "Auctioning " << item << " at starting price $" << start_price << endl;

    /* accept the starting bid */
    auctioneer.accept_bid(start_price);

    /* drive the auction */
    if (auctioneer.get_highest_bidder() == nullptr) {
        /* no participants */
        cout << "No participants" << endl;
    } else {
        /* print the results */
        cout << "\n" << item << " goes to "
             << auctioneer.get_highest_bidder()->get_name() << " for $" << auctioneer.get_highest_bid() << endl;
        cout << endl;
        /* print the bidders and their final highest bids */
        for (Bidder * bidder: auctioneer.get_bidders()) {
            cout << "Bidder: " << bidder->get_name()
                 << ", Highest bid: $" << bidder->get_highest_bid()
                 << endl;
        }
    }
}