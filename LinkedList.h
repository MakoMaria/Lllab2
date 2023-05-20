#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void addToStart(int value);
    void addToEnd(int value);
    void addAtPosition(int value, int position);
    void removeByValue(int value);
    void removeByPosition(int position);
    int searchByValue(int value);
    int searchByPosition(int position);
    void print();
    void clear();
    bool isEmpty();
};

#endif
