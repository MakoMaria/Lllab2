#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

class Stack {
private:
    LinkedList list;

public:
    void push(int value);
    int pop();
    int top();
    bool isEmpty();
};

#endif
