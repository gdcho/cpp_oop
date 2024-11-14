//
// Created by jyim3 on 2022-10-19.
//

#include "auctioneer.hpp"

/**
 * Adds a bidder to the list of tracked bidders
 * @param bidder: object with __call__(auctioneer) interface
 */
void Auctioneer::register_bidder(Bidder * bidder)
{
    /* add the bidder to the list of bidders */
    bidders.push_back(bidder);
}

/**
 * Resets the auctioneer. Removes all the bidders
 * and resets the highest bid to 0
 */
void Auctioneer::reset_auctioneer()
{
    /* clear the list of bidders */
    bidders.clear();
    /* set the highest bid to 0 */
    highest_bid = ZERO;
    /* set the highest bidder to nullptr */
    highest_bidder = nullptr;
}

/**
 * Executes all the bidder callbacks. Should only be called if the
 * highest bid has changed
 */
void Auctioneer::notify_bidders()
{
    for (Bidder * bidder: bidders) {
        /* notify all the bidders except the highest bidder */
        if (bidder != highest_bidder)
            bidder->update(this);
    }
}

/**
 * Accepts a new bid and updates the highest bid. This notifies all
 * the bidders via their callbacks
 * @param bid: a double, the bid
 * @param bidder: The bidder that placed the bid
 */
void Auctioneer::accept_bid(double bid, Bidder *bidder)
{
    /* if highest bid is 0, set the highest bid to the bid */
    if (highest_bid == ZERO) {
        /* set the highest bid to the bid */
        highest_bid = bid;
        /* set the highest bidder to the bidder */
        highest_bidder = bidder;
        /* notify all the bidders */
        notify_bidders();
    } else if (bid > highest_bid) { /* if the bid is higher than the highest bid */
        /* set first bid to false */
        is_first_bid = false;
        /* set the highest bid to the bid */
        highest_bid = bid;
        /* set the highest bidder to the bidder */
        highest_bidder = bidder;
        /* notify all the bidders */
        notify_bidders();
    }
}
