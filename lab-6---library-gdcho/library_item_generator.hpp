//
// Created by David Cho on 2024-10-15.
//

#pragma once
#include "library_item.hpp"
#include <iostream>
#include <string>

/**
 * Class representing the LibraryItemGenerator, responsible for generating new LibraryItems.
 */
class LibraryItemGenerator {
public:
    /**
     * Generate a new LibraryItem
     * @return a pointer to the newly generated LibraryItem
     */
    static LibraryItem* generate_item();
};
