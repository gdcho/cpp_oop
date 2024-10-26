//
// Created by David Cho on 2024-09-30.
//

#ifndef ABSTRACT_OPERATION_HPP
#define ABSTRACT_OPERATION_HPP

#include "operation.hpp"

/*
 * @brief Abstract class for operations
 * @details This class is an abstract class that is used to create the operations for the RPN calculator.
 *
 * @param operation_type the type of operation that is being performed.
 * Private: operation_type the type of operation that is being performed.
 * Public: get_code() returns the operation type.
 * Destructor: ~abstract_operation() virtual destructor for the abstract class.
 */
class abstract_operation : public operation {
private:
    // the operation type data member that is being performed
    char operation_type;
public:
    // constructor for the abstract operation
    abstract_operation(char type) : operation_type(type) {}

    // gets and returns the operation type
    virtual char get_code() override {
        return operation_type;
    }

    // destructor for the abstract operation
    virtual ~abstract_operation() {}
};

#endif //ABSTRACT_OPERATION_HPP
