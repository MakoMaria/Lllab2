#include "Stack.h"
#include "iostream"

void Stack::push(int value) {
    list.addToStart(value);
}

int Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return 0;
    }

    int topValue = list.searchByPosition(1);
    list.removeByPosition(1);
    return topValue;
}

int Stack::top() {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return 0;
    }

    return list.searchByPosition(1);
}

bool Stack::isEmpty() {
    return list.isEmpty();
}
