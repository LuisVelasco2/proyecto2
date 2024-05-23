#include <iostream>
#include "Stack.h"

int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top of stack: " << stack.top() << std::endl;

    stack.pop();
    std::cout << "Top of stack after pop: " << stack.top() << std::endl;

    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}

