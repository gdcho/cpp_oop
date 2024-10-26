//
// Created by David Cho on 2024-09-30.
//

#ifndef ADDITION_OPERATION_HPP
#define ADDITION_OPERATION_HPP

#include "abstract_operation.hpp"

/*
 * @brief Addition operation class
 * @details This class is used to add two numbers together.
 *
 * @param ADDITION_CODE the code for the addition operation.
 * Constructor: addition_operation() constructor for the addition operation.
 * perform() adds two numbers together.
 * Destructor: ~addition_operation() virtual destructor for the addition operation.
 */
class addition_operation : public abstract_operation {
public:
    // constant char for the code for the addition operation
    static constexpr char ADDITION_CODE = '+';

    // constructor for the addition operation
    addition_operation() : abstract_operation(ADDITION_CODE) {}

    // member function that adds two numbers together
    virtual int perform(int a, int b) override {return a + b;}

    // virtual destructor for the addition operation
    virtual ~addition_operation() {}
};

#endif //ADDITION_OPERATION_HPP
