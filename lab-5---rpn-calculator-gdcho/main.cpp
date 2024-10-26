//Name: David Cho
//Student# : A01351217

#include <iostream>
#include "rpn_calculator.hpp"

/*
 * @brief Main function
 * @details This function is the main function that is used to run the RPN calculator.
 * @param formula the formula that the user enters.
 * @param calculator the RPN calculator object.
 * @param result the result of the formula.
 * @return 0
 */
int main()
{
    // get the formula from the user
    std::cout << "Enter your formula:\n";
    // read the formula
    std::string formula;
    // store the formula by line from the user input
    std::getline(std::cin, formula);
    // print the formula
    std::cout << "You entered: " << formula << std::endl;
    // create the RPN calculator object
    RPNCalculator calculator;
    // process the formula and store the result
    int result = calculator.process_formula(formula);
    // print the result
    std::cout << "The result is:\n";
    std::cout << result << std::endl;
    return 0;
}