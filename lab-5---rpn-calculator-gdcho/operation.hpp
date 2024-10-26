//
// Created by David Cho on 2024-09-30.
//

#ifndef OPERATION_HPP
#define OPERATION_HPP

/*
 * @brief Operation class
 * @details This class is an abstract class that is used to create the operations for the RPN calculator.
 * @param get_code() returns the operation type.
 * @param perform() performs the operation.
 * Destructor: ~operation() virtual destructor for the operation class.
 */
class operation
{
public:
    // member function that gets and returns the operation type
    virtual char get_code() = 0;
    // member function performs the operation
    virtual int perform(int a, int b) = 0;
    // virtual destructor for the operation class
    virtual ~operation() {}
};
#endif //OPERATION_HPP
