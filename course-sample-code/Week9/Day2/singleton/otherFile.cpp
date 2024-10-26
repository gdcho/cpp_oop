//
// Created by A00257049 on 2019-03-27.
//

#include "otherFile.hpp"
#include "singleton.hpp"
#include <iostream>

using namespace std;
void function() {
    cout << "otherFile function: " << singleton::get_instance().get_value();
}