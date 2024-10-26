//
// Created by David Cho on 2024-09-30.
//

#ifndef SUBTRACTION_OPERATION_HPP
#define SUBTRACTION_OPERATION_HPP

#include "abstract_operation.hpp"

/*
 * @brief Subtraction operation class
 * @details This class is used to subtract two numbers.
 *
 * @param SUBTRACTION_CODE the code for the subtraction operation.
 * Constructor: subtraction_operation() constructor for the subtraction operation.
 * perform() subtracts two numbers.
 * Destructor: ~subtraction_operation() virtual destructor for the subtraction operation.
 */
class subtraction_operation : public abstract_operation {
public:
    // constant char for the code for the subtraction operation
    static constexpr char SUBTRACTION_CODE = '-';

    // constructor for the subtraction operation
    subtraction_operation() : abstract_operation(SUBTRACTION_CODE) {}

    // member function that subtracts two numbers
    virtual int perform(int a, int b) override { return a - b; }

    // virtual destructor for the subtraction operation
    virtual ~subtraction_operation() {}
};

#endif //SUBTRACTION_OPERATION_HPP
