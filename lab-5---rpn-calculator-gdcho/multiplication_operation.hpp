//
// Created by David Cho on 2024-09-30.
//

#ifndef MULTIPLICATION_OPERATION_HPP
#define MULTIPLICATION_OPERATION_HPP

#include "abstract_operation.hpp"

/*
 * @brief Multiplication operation class
 * @details This class is used to multiply two numbers.
 *
 * @param MULTIPLICATION_CODE the code for the multiplication operation.
 * Constructor: multiplication_operation() constructor for the multiplication operation.
 * perform() multiplies two numbers.
 * Destructor: ~multiplication_operation() virtual destructor for the multiplication operation.
 */
class multiplication_operation : public abstract_operation {
public:
    // constant char for the code for the multiplication operation
    static constexpr char MULTIPLICATION_CODE = '*';

    // constructor for the multiplication operation
    multiplication_operation() : abstract_operation(MULTIPLICATION_CODE) {}

    // member function that multiplies two numbers
    virtual int perform(int a, int b) override { return a * b; }

    // virtual destructor for the multiplication operation
    virtual ~multiplication_operation() {}
};

#endif //MULTIPLICATION_OPERATION_HPP
