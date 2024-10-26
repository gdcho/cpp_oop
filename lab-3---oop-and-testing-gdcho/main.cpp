//Name: David Cho
//Student# : A01351217

#include <iostream>
#include "myStack.hpp"

using namespace std;

// int main() {
//
//     MyStack stack;
//
//     // print empty stack with topIndex initialized at -1
//     stack.print();
//
//     // should print true for empty
//     cout << "Empty? " << (stack.empty() ? "true" : "false") << endl;
//
//     // checks to see top of empty stack
//     cout << "top: " << stack.top() << endl;
//     // able to pop
//     cout << "Able to pop? " << stack.pop() << endl;
//
//     stack.push(1);
//     stack.push(2);
//     stack.push(3);
//     // should print 1 2 3 from bottom to top
//     stack.print();
//
//     // should print false
//     cout << "Empty? " << (stack.empty() ? "true" : "false") << endl;
//
//
//     // top element should print 3
//     cout << "Top element: " << stack.top() << endl;
//
//     // check for full
//     cout << "Full? " << (stack.full() ? "true" : "false") << endl;
//
//     stack.push(4);
//     stack.push(5);
//     stack.push(6);
//     stack.push(7);
//     stack.push(8);
//     stack.push(9);
//
//     // check to see if able to push
//     cout << "Able to push? " << (stack.push(10) ? "true" : "false") << endl;
//
//     // check for full
//     cout << "Full? " << (stack.full() ? "true" : "false") << endl;
//
//     stack.print();
//     // check to see if able to push
//     cout << "Able to push? " << (stack.push(11) ? "true" : "false") << endl;
//
//     stack.pop();
//     stack.print();
//
//     return 0;
// }
