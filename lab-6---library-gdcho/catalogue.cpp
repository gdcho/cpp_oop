//
// Created by David Cho on 2024-10-15.
//

// catalogue.cpp
#include "catalogue.hpp"
#include "library_item_generator.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Initialize the catalogue with a list of items
 * @param items a vector of LibraryItem pointers
 */
Catalogue::Catalogue(const vector<LibraryItem*>& items) : items(items) {}

/**
 * Destructor to clean up dynamically allocated memory
 */
Catalogue::~Catalogue() {
    for (LibraryItem* item : items) {
        delete item;
    }
}

/**
 * Retrieve an item by call number
 * @param call_number the call number of the item
 * @return a pointer to the LibraryItem if found, nullptr otherwise
 */
LibraryItem* Catalogue::retrieve_item_by_call_number(const string& call_number) {
    for (LibraryItem* item : items) {
        if (item->get_call_number() == call_number) {
            return item;
        }
    }
    return nullptr;
}

/**
 * Find items by title
 * @param title the title of the items to find
 * @return a vector of pointers to LibraryItem
 */
vector<LibraryItem*> Catalogue::find_items(const string& title) {
    vector<LibraryItem*> found_items;
    for (LibraryItem* item : items) {
        if (item->get_title() == title) {
            found_items.push_back(item);
        }
    }
    return found_items;
}

/**
 * Add a new item to the catalogue
 */
void Catalogue::add_item() {
    LibraryItem* new_item = LibraryItemGenerator::generate_item();
    if (new_item == nullptr) {
        cout << "Failed to create new item.\n";
        return;
    }
    if (retrieve_item_by_call_number(new_item->get_call_number())) {
        cout << "Item with call number " << new_item->get_call_number() << " already exists.\n";
        delete new_item;
    } else {
        items.push_back(new_item);
        cout << "Item added successfully!\n";
        cout << *new_item;
    }
}

/**
 * Remove an item from the catalogue by call number
 * @param call_number the call number of the item to remove
 */
void Catalogue::remove_item(const string& call_number) {
    LibraryItem* item = retrieve_item_by_call_number(call_number);
    if (item) {
        items.erase(remove(items.begin(), items.end(), item), items.end());
        cout << "Successfully removed item with call number: " << call_number << "\n";
        delete item;
    } else {
        cout << "Item with call number " << call_number << " not found.\n";
    }
}

/**
 * Display all available items in the catalogue
 */
void Catalogue::display_available_items() {
    cout << "Items List\n";
   cout << "--------------\n\n";
    for (LibraryItem* item : items) {
        cout << *item << "\n";
    }
}

/**
 * Decrement the item count for an item with the given call number
 * @param call_number the call number of the item
 * @return true if the item was found and count decremented, false otherwise
 */
bool Catalogue::reduce_item_count(const string& call_number) {
    LibraryItem* item = retrieve_item_by_call_number(call_number);
    if (item && item->check_availability()) {
        item->decrement_number_of_copies();
        return true;
    }
    return false;
}

/**
 * Increment the item count for an item with the given call number
 * @param call_number the call number of the item
 * @return true if the item was found and count incremented, false otherwise
 */
bool Catalogue::increment_item_count(const string& call_number) {
    LibraryItem* item = retrieve_item_by_call_number(call_number);
    if (item) {
        item->increment_number_of_copies();
        return true;
    }
    return false;
}
