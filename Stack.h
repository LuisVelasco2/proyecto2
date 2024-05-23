//
// Created by LUIS on 10/04/2024.
//

#ifndef PROGRAMACIONIV_STACK_H
#define PROGRAMACIONIV_STACK_H


#include "DLList.h"

template<typename T>
class Stack : private DLList<T> {
public:
    void push(const T& data) {
        this->push_front(data);
    }

    void pop() {
        this->pop_front();
    }

    T& top()  {
        if (this->isEmpty()) {
            throw std::runtime_error("Stack is empty.");
        }
        return this->begin()->data;
    }

    bool isEmpty() const {
        return DLList<T>::isEmpty();
    }
};



#endif //PROGRAMACIONIV_STACK_H
