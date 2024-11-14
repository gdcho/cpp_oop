//
// Created by jyim3 on 2022-10-19.
//

#include "bidder.hpp"
#include "auctioneer.hpp"

/**
 * update is called by the auctioneer when they need to notify
 * the bidder of something important
 * @param auctioneer: pointer to the auctioneer object
 */
void Bidder::update(Auctioneer * auctioneer) {
    /* constant for 100 */
    double const HUNDRED = 100;
    /* generate a random number between 0 and 100 */
    double random_number = (double) rand() / RAND_MAX * HUNDRED;
    /* get the highest bid */
    double auction_high_bid = auctioneer->get_highest_bid();
    /* calculate the bid increase */
    double bid_increase = auctioneer->get_highest_bid() * bid_increase_perc;
    /* get the highest bidder */
    Bidder * highest_bidder = auctioneer->get_highest_bidder();

    /* if the bidder is not the highest bidder */
    if (auctioneer->get_highest_bidder() != this) {
        /* if the bid increase is less than the budget and the random number is less than the bid probability */
        if (bid_increase <= budget) {
            /* if the random number is less than the bid probability */
            if (random_number <= bid_probability) {
                /* if it is the first bid */
                if (auctioneer->get_is_first_bid()) {
                    cout << name << " bidded $"
                         << bid_increase << " in response to the Starting bid of $"
                         << auction_high_bid << endl;
                    /* set the highest bid to the bid */
                    highest_bid = bid_increase;
                    /* accept the bid */
                    auctioneer->accept_bid(bid_increase, this);
                } else {
                    cout << name << " bidded $"
                         << bid_increase << " in response to "
                         << *highest_bidder << "'s bid of $"
                         << (int)auction_high_bid << endl;
                    /* set the highest bid to the bid */
                    highest_bid = bid_increase;
                    /* accept the bid */
                    auctioneer->accept_bid(bid_increase, this);
                }
            }
        }
    }
}