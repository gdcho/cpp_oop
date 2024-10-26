//
// Created by David Cho on 2024-09-16.
//

#include "myStack.hpp"
#include <iostream>

using namespace std;

MyStack::MyStack() : topIndex(-1) {}

// add element to the top of stack if stack is not full and return true
bool MyStack::push(int element) {
    if (full()) {
        return false;
    }
    arr[++topIndex] = element;
    return true;
}

// remove the top element of the stack if stack is not empty
int MyStack::pop() {
    if (empty()) {
        throw out_of_range("Pop out of range");
    }
    return arr[topIndex--];
}

// returns the top element of the stack
int MyStack::top() const {
    // if empty output error message
    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
    // return the top element
    return arr[topIndex];
}

// checks to see if topIndex == -1, which is the initialized value
bool MyStack::empty() const {
    if (topIndex == -1)
    {
        return true;
    }
    return false;
}

// checks to see if stack is full by comparing to MAX_SIZE
bool MyStack::full() const {
    return topIndex == MAX_SIZE - 1;
}

// prints all the stack
void MyStack::print() const {
    if (empty()) {
        cout << "empty stack with top index at: " << topIndex << endl;
        return;
    }
    cout << "Stack from bottom to top: ";
    for (int i = 0; i <= topIndex; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
