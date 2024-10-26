//
// Created by jyim3 on 2022-10-19.
//

#pragma once
#include "library_item.hpp"
using namespace std;

/**
 * Class representing a Book, derived from LibraryItem.
 * Contains additional attribute 'author'.
 **/
class Book : public LibraryItem {
private:
    string author;  // author of the book

public:
    /**
     * Initialize the book with a call number, title, number of copies and author
     * @param call_num
     * @param title
     * @param num_copies
     * @param author
     */
    Book(const string& call_num, const string& title, int num_copies, const string& author)
        : LibraryItem(call_num, title, num_copies), author(author) {}

    /**
     * Get the author of the book
     * @return author
     */
    string get_author() const { return author; }

    /**
     * Print the details of the book
     * @param os output stream
     */
    void print(ostream& os) const override {
        os << "---- Book: " << title << " ----\n"
           << "Call Number: " << call_num << "\n"
           << "Number of Copies: " << num_copies << "\n"
           << "Author: " << author << "\n";
    }
};
