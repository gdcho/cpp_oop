//
// Created by jyim3 on 2022-10-19.
//

#pragma once
#include "catalogue.hpp"
using namespace std;

/**
 * Class representing the Library.
 * It provides an interface for users to interact with the catalogue.
 **/
class Library {
private:
        Catalogue catalogue;  // instance of Catalogue

public:
        /**
         * Initialize the library with a list of items
         * @param items a vector of LibraryItem pointers
         */
        Library(const vector<LibraryItem*>& items);

        /**
         * Check out an item by call number
         * @param call_number the call number of the item to check out
         */
        void check_out(const string& call_number);

        /**
         * Return an item by call number
         * @param call_number the call number of the item to return
         */
        void return_item(const string& call_number);

        /**
         * Display the library menu
         */
        void display_library_menu();
};