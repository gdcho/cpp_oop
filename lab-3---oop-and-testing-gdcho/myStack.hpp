//
// Created by David Cho on 2024-09-16.
//

#ifndef MYSTACK_HPP
#define MYSTACK_HPP

// MyStack class implements a custom stack data structure.
// The stack includes operations like push, pop, and top.

// max size of the stack
constexpr int MAX_SIZE = 10;

class MyStack {
private:
    // array of size MAX_SIZE to store stack elements
    int arr[MAX_SIZE]{};
    // top index
    int topIndex;

public:
    // Default constructor
    // POST: Creates an empty stack with topIndex initialized to -1
    MyStack();

    // Push an element onto the stack
    // PRE: integer to be added to the stack
    // POST: when stack is not full, element is added to the top while topIndex increments
    // RETURN: true if element was successfully added or else false
    bool push(int element);

    // Pop the top element from the stack
    // PRE: stack is not empty
    // POST: top element removed and topIndex decrements
    // RETURN: value of the removed top element or -1
    int pop();

    // Return the top element
    // PRE: Not empty stack
    // POST: stack does not change
    // RETURN: value of the top element or -1
    int top() const;

    // Check if stack is empty
    // POST: stack does not change
    // RETURN: true if stack is empty or else false
    bool empty() const;

    // Check if the stack is full
    // POST: stack does not change
    // RETURN: true if stack is full or else false
    bool full() const;

    // Print stack from bottom to top
    // POST: stack does not change, standard output prints contents
    void print() const;
};


#endif //MYSTACK_HPP
