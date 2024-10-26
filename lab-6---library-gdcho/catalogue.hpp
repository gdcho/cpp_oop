//
// Created by David Cho on 2024-10-15.
//

#pragma once
#include <vector>
#include "library_item.hpp"
using namespace std;

/*
 * Class representing the Catalogue, responsible for managing library items.
 * It provides methods to add, remove, find, and display items.
 */
class Catalogue {
private:
    vector<LibraryItem*> items;  // vector of pointers to LibraryItem

public:
    /**
     * Initialize the catalogue with a list of items
     * @param items a vector of LibraryItem pointers
     */
    Catalogue(const vector<LibraryItem*>& items);

    /**
     * Destructor to clean up dynamically allocated memory
     */
    ~Catalogue();

    /**
     * Retrieve an item by call number
     * @param call_number the call number of the item
     * @return a pointer to the LibraryItem if found, nullptr otherwise
     */
    LibraryItem* retrieve_item_by_call_number(const string& call_number);

    /**
     * Find items by title
     * @param title the title of the items to find
     * @return a vector of pointers to LibraryItem
     */
    vector<LibraryItem*> find_items(const string& title);

    /**
     * Add a new item to the catalogue
     */
    void add_item();

    /**
     * Remove an item from the catalogue by call number
     * @param call_number the call number of the item to remove
     */
    void remove_item(const string& call_number);

    /**
     * Display all available items in the catalogue
     */
    void display_available_items();

    /**
     * Display the catalogue menu
     */
    bool reduce_item_count(const string& call_number);

    /**
     * Increment the item count for an item with the given call number
     * @param call_number the call number of the item
     * @return true if the item was found and count incremented, false otherwise
     */
    bool increment_item_count(const string& call_number);
};
