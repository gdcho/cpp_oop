//
// Created by David Cho on 2024-10-15.
//

#pragma once
#include "library_item.hpp"
using namespace std;

/**
 * Class representing a Journal, derived from LibraryItem.
 * Contains additional attributes 'author', 'issue_number', and 'publisher'.
 **/
class Journal : public LibraryItem {
private:
    string author;        // author
    string issue_number;  // issue number
    string publisher;     // Publisher

public:
    /**
     * Initialize the journal with a call number, title, number of copies, author, issue number, and publisher
     * @param call_num
     * @param title
     * @param num_copies
     * @param author
     * @param issue_number
     * @param publisher
     */
    Journal(const string& call_num, const string& title, int num_copies,
            const string& author, const string& issue_number, const string& publisher)
        : LibraryItem(call_num, title, num_copies), author(author), issue_number(issue_number), publisher(publisher) {}

    /**
     * Print the details of the journal
     * @param os output stream
     */
    void print(ostream& os) const override {
        os << "---- Journal: " << title << " ----\n"
           << "Call Number: " << call_num << "\n"
           << "Number of Copies: " << num_copies << "\n"
           << "Author: " << author << "\n"
           << "Issue Number: " << issue_number << "\n"
           << "Publisher: " << publisher << "\n";
    }
};
