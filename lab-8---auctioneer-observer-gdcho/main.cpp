//Student Name: David Cho
//Student Number: A01351217

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "bidder.hpp"
#include "auction.hpp"

/**
 * Generates a random number between min and max
 * @param min: double, minimum value
 * @param max: double, maximum value
 * @return double, random number between min and max
 */
double generateRandom(double min, double max)
{
    double f = (double) rand() / RAND_MAX;
    return min + f * (max - min);
}

/**
 * Displays the menu and drives the auction
 * @param bidders: vector of Bidder pointers
 * @param item: string, name of the item
 * @param start_price: float, starting price of the item
 */
void menu(vector<Bidder *> &bidders, string item, double start_price) {
    /* variable to store the option */
    int option;

    /* display the menu */
    do {
        cout << endl;
        cout << "Welcome to the Auction House!!" << endl;
        cout << "------------------" << endl;
        cout << "Here are your choices:" << endl;
        cout << "1. Start Auction" << endl;
        cout << "2. Add More Bidders" << endl;
        cout << "3. Exit" << endl;
        cout << "------------------" << endl;
        cout << "Choose an option (1-3): ";

        cin >> option;
        cin.ignore();

        /* if the option is 1, start the auction */
        if (option == 1) {
            cout << endl;
            cout << "Starting Auction!!" << endl;
            cout << "------------------" << endl;
            /* create an auction object */
            Auction my_auction(bidders);
            /* simulate the auction */
            my_auction.simulate_auction(item, start_price);
        } else if (option == 2) {
            /* if the option is 2, add more bidders */
            cout << "Do you want to add more bidders? (y/n): ";
            string choice;
            cin >> choice;

            cin.ignore();

            while (choice == "y") {
                cout << "Enter bidder name: ";
                string name;
                getline(cin, name);

                cout << "Enter bidder budget: ";
                double budget;
                cin >> budget;

                cin.ignore();

                cout << "Enter bidder bid probability (between 0 and 1): ";
                double bidProbability;
                cin >> bidProbability;

                cin.ignore();

                cout << "Enter bidder bid increase percentage (greater than 1): ";
                double bidIncreasePercentage;
                cin >> bidIncreasePercentage;

                cin.ignore();

                /* add the bidder to the list of bidders */
                bidders.push_back(new Bidder(name, budget, bidProbability, bidIncreasePercentage));

                cout << "Do you want to add more bidders? (y/n): ";
                cin >> choice;

                cin.ignore();
            }
        } else if (option == 3) {
            /* if the option is 3, exit the program */
            cout << "Exiting the program." << endl;
            exit(0);
        } else {
            /* if the option is invalid, display an error message */
            cout << "Invalid option. Try again." << endl;
        }
    } while (option != 3);
}

/**
 * Starts the auction
 * @param bidders: vector of Bidder pointers
 */
void start(vector<Bidder *> &bidders) {
    /* variable to store the item name */
    string item_name;
    /* variable to store the starting price */
    double start_price;

    /* get the item name */
    cout << "Enter the name of the item being auctioned: ";
    getline(cin, item_name);
    /* get th item starting price */
    cout << "Enter the starting price: ";
    cin >> start_price;

    cin.ignore();

    /* display the menu */
    menu(bidders, item_name, start_price);
}

/**
 * Main function that initializes the bidders and starts the auction
 * @return 0
 */
int main() {
    /* vector to store the bidders */
    vector<Bidder *> bidders;
    /* constants for the minimum and maximum bid */
    const double MIN_BID = 0;
    const double MAX_BID = 100;
    /* seed the random number generator */
    srand(time(0));

    /* hardcoding the bidders */
    bidders.push_back(new Bidder("Jojo", 3000, generateRandom(MIN_BID, MAX_BID), 1.2));
    bidders.push_back(new Bidder("Melissa", 7000, generateRandom(MIN_BID, MAX_BID), 1.5));
    bidders.push_back(new Bidder("Priya", 15000, generateRandom(MIN_BID, MAX_BID), 1.1));
    bidders.push_back(new Bidder("Kewei", 800, generateRandom(MIN_BID, MAX_BID), 1.9));
    bidders.push_back(new Bidder("Scott", 4000, generateRandom(MIN_BID, MAX_BID), 2));

    /* start the auction */
    start(bidders);
    /* delete the bidders */
    for (Bidder * bidder: bidders) { delete bidder; }

    return 0;
}
