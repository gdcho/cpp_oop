//
// Created by David Cho on 2024-10-15.
//

#pragma once
#include "library_item.hpp"
using namespace std;

/**
 * Class representing a DVD, derived from LibraryItem.
 * Contains additional attributes 'release_date' and 'region_code'.
 **/
class DVD : public LibraryItem {
private:
    string release_date;  // release date
    string region_code;   // region code

public:
    /**
     * Initialize the DVD with a call number, title, number of copies, release date, and region code
     * @param call_num
     * @param title
     * @param num_copies
     * @param release_date
     * @param region_code
     */
    DVD(const string& call_num, const string& title, int num_copies,
        const string& release_date, const string& region_code)
        : LibraryItem(call_num, title, num_copies), release_date(release_date), region_code(region_code) {}

    /**
     * Print the details of the DVD
     * @param os output stream
     */
    void print(ostream& os) const override {
        os << "---- DVD: " << title << " ----\n"
           << "Call Number: " << call_num << "\n"
           << "Number of Copies: " << num_copies << "\n"
           << "Release Date: " << release_date << "\n"
           << "Region Code: " << region_code << "\n";
    }
};