//
// Created by David Cho on 2024-10-15.
//

#include "library_item_generator.hpp"
#include "book.hpp"
#include "dvd.hpp"
#include "journal.hpp"
using namespace std;

/**
 * Helper function to clear the input buffer
 */
void clean_cin_generator() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * Generate a new LibraryItem based on user input
 * @return a pointer to the newly generated LibraryItem
 */
LibraryItem* LibraryItemGenerator::generate_item() {
    cout << "Select the type of item to add:\n";
    cout << "1. Book\n";
    cout << "2. DVD\n";
    cout << "3. Journal\n";
    cout << "Enter your choice (1-3): ";

    int choice;
    cin >> choice;
    clean_cin_generator();

    // common attributes for all items
    string call_number, title;
    int num_copies;

    cout << "Enter Call Number: ";
    getline(cin, call_number);

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Number of Copies: ";
    cin >> num_copies;
    clean_cin_generator();

    // create item based on the user's choice
    switch (choice) {
        case 1: { // Book
            string author;
            cout << "Enter Author: ";
            getline(cin, author);
            return new Book(call_number, title, num_copies, author);
        }
        case 2: { // DVD
            string release_date, region_code;
            cout << "Enter Release Date: ";
            getline(cin, release_date);
            cout << "Enter Region Code: ";
            getline(cin, region_code);
            return new DVD(call_number, title, num_copies, release_date, region_code);
        }
        case 3: { // Journal
            string author, issue_number, publisher;
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter Issue Number: ";
            getline(cin, issue_number);
            cout << "Enter Publisher: ";
            getline(cin, publisher);
            return new Journal(call_number, title, num_copies, author, issue_number, publisher);
        }
        default:
            cout << "Invalid choice.\n";
            return nullptr;
    }
}
