//
// Created by David Cho on 2024-09-30.
//

#ifndef DIVISION_OPERATION_HPP
#define DIVISION_OPERATION_HPP

#include "abstract_operation.hpp"

/*
 * @brief Division operation class
 * @details This class is used to divide two numbers.
 *
 * @param DIVISION_CODE the code for the division operation.
 * Constructor: division_operation() constructor for the division operation.
 * perform() divides two numbers.
 * Destructor: ~division_operation() virtual destructor for the division operation.
 */
class division_operation : public abstract_operation {
public:
    // constant char for the code for the division operation
    static constexpr char DIVISION_CODE = '/';

    // constructor for the division operation
    division_operation() : abstract_operation(DIVISION_CODE) {}

    // member function that divides two numbers
    virtual int perform(int a, int b) override { return a / b; }

    // virtual destructor for the division operation
    virtual ~division_operation() {}
};

#endif //DIVISION_OPERATION_HPP
