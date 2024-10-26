//Name: David Cho
//Student# : A01351217

#include "library.hpp"
#include "book.hpp"
#include "dvd.hpp"
#include "journal.hpp"
#include <vector>
using namespace std;

/**
 * Function to generate test items with dummy data.
 * Returns a vector of LibraryItem pointers.
 **/
vector<LibraryItem*> generate_test_items() {
    // create a vector of LibraryItem pointers
    vector<LibraryItem*> items;
    // add books
    items.push_back(new Book("100.200.300", "Harry Potter 1", 2, "J.K. Rowling"));
    items.push_back(new Book("999.224.854", "Harry Potter 2", 5, "J.K. Rowling"));
    items.push_back(new Book("631.495.302", "Harry Potter 3", 4, "J.K. Rowling"));
    items.push_back(new Book("123.02.204", "The Cat in the Hat", 1, "Dr. Seuss"));
    // add dvd
    items.push_back(new DVD("200.100.300", "Inception", 3, "2010-07-16",
        "Region 1"));
    // add journal
    items.push_back(new Journal("300.200.100", "Nature Journal", 2, "Various",
        "Vol. 10", "Nature Publishing"));
    return items;
}

int main() {
    // generate test items
    vector<LibraryItem*> items = generate_test_items();
    // create library with the test items
    Library library(items);
    // display the library menu
    library.display_library_menu();
    return 0;
}