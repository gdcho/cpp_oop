//
// Created by David Cho on 2024-09-30.
//

#ifndef RPN_CALCULATOR_HPP
#define RPN_CALCULATOR_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>

#include "addition_operation.hpp"
#include "subtraction_operation.hpp"
#include "multiplication_operation.hpp"
#include "division_operation.hpp"

/*
 * @brief RPN Calculator class
 * @details This class is used to process the formula for the RPN calculator.
 *
 * @param result the result of the formula.
 * @param myStack the stack that holds the numbers.
 * Private: operation_type() determines the type of operation.
 * perform() performs the operation.
 * Public: process_formula() processes the formula.
 */
class RPNCalculator {
private:
    // the result of the formula
    int result;
    // the stack that holds the numbers
    std::stack<int> myStack;

    // determine operation type by passing pointer to operation
    operation* operation_type(char myOperation) {
        // switch statements based on public constants in operation classes
        switch (myOperation) {
            // addition operation
            case addition_operation::ADDITION_CODE:
                return new addition_operation();
            // subtraction operation
            case subtraction_operation::SUBTRACTION_CODE:
                return new subtraction_operation();
            // multiplication operation
            case multiplication_operation::MULTIPLICATION_CODE:
                return new multiplication_operation();

            case division_operation::DIVISION_CODE:
                return new division_operation();
            default:
                return nullptr;
        }
    }

    // performs the operation with the top two numbers on the stack
    // and accepts the operation pointer
    void perform(operation* myOperation) {
        // if stack has less than 2 operands, throw error
        if (myStack.size() < 2) {
            std::cerr << "Error, requires 2 operands.\n";
            // delete the operation pointer
            delete myOperation;
            return;
        }
        // get the top two numbers from stack and pop
        int b = myStack.top(); myStack.pop();
        int a = myStack.top(); myStack.pop();
        // perform the operation with the two numbers
        int res = myOperation->perform(a, b);
        // push the result back onto the stack
        myStack.push(res);
    }

public:
    // processes the formula and returns the result
    int process_formula(const std::string& formula) {
        // create input stream from the formula string
        std::istringstream iss(formula);
        // create a string to store the current token
        std::string operand;

        // reads tokens from the input stream until the end of the stream
        while (iss >> operand) {
            // create a new input stream from the token
            std::istringstream iss2(operand);
            int number;

            // if iss2 is able to be converted to an integer, push it onto the stack
            if (iss2 >> number) {
                myStack.push(number);
            }
            // check if the token is an operation
            else if (operand.length() == 1) {
                // determine the operation type
                operation* myOperation = operation_type(operand[0]);

                // if valid operation, perform operation
                if (myOperation != nullptr) {
                    perform(myOperation);
                    delete myOperation;
                }
                // if operation does not exist, throw error
                else {
                    std::cerr << "Error, unknown operation '" << operand[0] << "'.\n";
                }
            }
            // if token is not an integer or operation, throw error
            else {
                std::cerr << "Error, invalid token '" << operand << "'.\n";
            }
        }

        // after processing the formula, check to see if there is a result on the stack
        if (!myStack.empty()) {
            // get result from the top and pop it off the stack
            result = myStack.top();
            myStack.pop();

            // if stack is still not empty, throw error
            if (!myStack.empty()) {
                std::cerr << "Stack still not empty after formula processing.\n";
            }

            return result;
        }
        // if stack is empty with no result, throw error
        else {
            std::cerr << "Error, no result on stack.\n";
            return 0;
        }
    }
};

#endif //RPN_CALCULATOR_HPP
