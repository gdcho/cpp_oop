//
// Created by David Cho on 2024-10-15.
//

// library_item.hpp
#pragma once
#include <string>
#include <iostream>

using namespace std;
/*
 * Abstract base class representing a generic library item.
 * It contains common attributes and methods shared by all library items.
 */
class LibraryItem {
protected:
    string call_num;  // unique call number identifier
    string title;     // title of the item
    int num_copies;        // number of copies available

public:
    /**
     * Initialize the library item with a call number, title and number of copies
     * @param call_num
     * @param title
     * @param num_copies
     */
    LibraryItem(const string& call_num, const string& title, int num_copies)
        : call_num(call_num), title(title), num_copies(num_copies) {}

    /**
     * Virtual destructor to ensure proper cleanup of derived classes
     */
    virtual ~LibraryItem() = default;

    /**
     * Get the title of the library item
     * @return title
     */
    string get_title() const { return title; }

    /**
     * Get the call number of the library item
     * @return call number
     */
    string get_call_number() const { return call_num; }

    /**
     * Get the number of copies of the library item
     * @return number of copies
     */
    int get_num_copies() const { return num_copies; }

    /**
     * Increment the number of copies of the library item
     */
    void increment_number_of_copies() { num_copies++; }

    /**
     * Decrement the number of copies of the library item
     */
    void decrement_number_of_copies() { num_copies--; }

    /**
     * Check if the library item is available (i.e., has copies available)
     * @return true if available, false otherwise
     */
    bool check_availability() const { return num_copies > 0; }

    /**
     * Print the library item to the output stream
     * @param os output stream
     */
    virtual void print(ostream& os) const = 0;

    /**
     * Overload the << operator to print the library item
     * @param os output stream
     * @param item library item
     * @return output stream
     */
    friend ostream& operator<<(ostream& os, const LibraryItem& item) {
        item.print(os);
        return os;
    }
};
