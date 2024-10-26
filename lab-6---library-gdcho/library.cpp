//
// Created by jyim3 on 2022-10-19.
//

#include "library.hpp"
#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

/**
 * Helper function to clean the cin buffer
 */
void clean_cin_library() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * Initialize the library with a list of items
 * @param items a vector of LibraryItem pointers
 */
Library::Library(const vector<LibraryItem*>& items) : catalogue(items) {}

/**
 * Check out an item by call number
 * @param call_number the call number of the item to check out
 */
void Library::check_out(const string& call_number) {
    if (catalogue.reduce_item_count(call_number)) {
        cout << "Checkout complete!\n";
    } else {
        cout << "Checkout failed. Item may not be available or does not exist.\n";
    }
}

/**
 * Return an item by call number
 * @param call_number the call number of the item to return
 */
void Library::return_item(const string& call_number) {
    if (catalogue.increment_item_count(call_number)) {
        cout << "Item returned successfully!\n";
    } else {
        cout << "Return failed. Item does not exist.\n";
    }
}

/**
 * Display the library menu
 */
void Library::display_library_menu() {
    int user_input = -1;

    while (user_input != 7) {
        // Display menu options
        cout << "\nWelcome to the Library!!!\n";
        cout << "-----------------------\n";
        cout << "1. Display all items\n";
        cout << "2. Check Out an item\n";
        cout << "3. Return an item\n";
        cout << "4. Find an item\n";
        cout << "5. Add an item\n";
        cout << "6. Remove an item\n";
        cout << "7. Quit\n";

        cout << "Please enter your choice (1-7): ";
        string string_input;
        cin >> string_input;
        stringstream ss{string_input};

        if (ss >> user_input) {
            switch (user_input) {
                case 1:
                    // Display all items
                    catalogue.display_available_items();
                    break;
                case 2: {
                    // Check out an item
                    cout << "Enter the call number of the item you wish to check out: ";
                    string call_number;
                    cin >> call_number;
                    check_out(call_number);
                    break;
                }
                case 3: {
                    // Return an item
                    cout << "Enter the call number of the item you wish to return: ";
                    string call_number;
                    cin >> call_number;
                    return_item(call_number);
                    break;
                }
                case 4: {
                    // Find an item
                    cout << "Enter the title of the item: ";
                    string input_title;
                    clean_cin_library();
                    getline(cin, input_title);
                    vector<LibraryItem*> found_items = catalogue.find_items(input_title);
                    if (!found_items.empty()) {
                        cout << "We found the following items:\n";
                        for (LibraryItem* item : found_items) {
                            cout << *item << "\n";
                        }
                    } else {
                        cout << "Sorry! No items found with that title.\n";
                    }
                    break;
                }
                case 5:
                    // Add an item
                    catalogue.add_item();
                    break;
                case 6: {
                    // Remove an item
                    cout << "Enter the call number of the item to remove: ";
                    string call_number;
                    cin >> call_number;
                    catalogue.remove_item(call_number);
                    break;
                }
                case 7:
                    // Quit
                    cout << "Thank you for visiting the Library.\n";
                    return;
                default:
                    cout << "Invalid choice. Please enter a number from 1-7.\n";
                    break;
            }
        } else {
            cout << "Could not process the input. Please enter a number from 1-7.\n";
            clean_cin_library();
        }
    }
}