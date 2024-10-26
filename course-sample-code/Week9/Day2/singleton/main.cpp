//
// Created by A00257049 on 2019-03-27.
//
#include <iostream>
#include "singleton.hpp"
#include "otherFile.hpp"
using namespace std;
int main()
{
    //singleton s1; //constructor is private, won't compile!
    //singleton s2 = singleton::get_instance(); //copy constructor deleted, won't compile!

    cout << singleton::get_instance().get_value() << "\n"; // better!

    singleton *sPtr = &singleton::get_instance();
    cout << sPtr->get_value() << "\n";

    singleton &sRef = singleton::get_instance();
    cout << sRef.get_value() << "\n";
//
    function();
    return 0;
}