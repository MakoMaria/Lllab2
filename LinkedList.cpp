#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::addToStart(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::addToEnd(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void LinkedList::addAtPosition(int value, int position) {
    if (position <= 0) {
        std::cout << "Invalid position!" << std::endl;
        return;
    }

    if (position == 1) {
        addToStart(value);
        return;
    }

    Node* current = head;
    int currentPosition = 1;
    while (current != nullptr && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == nullptr) {
        std::cout << "Invalid position!" << std::endl;
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = current->next;
    current->next = newNode;
}

void LinkedList::removeByValue(int value) {
    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next == nullptr) {
        std::cout << "Value not found!" << std::endl;
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

void LinkedList::removeByPosition(int position) {
    if (position <= 0) {
        std::cout << "Invalid position!" << std::endl;
        return;
    }

    if (position == 1) {
        if (head == nullptr) {
            std::cout << "List is empty!" << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    int currentPosition = 1;
    while (current != nullptr && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == nullptr || current->next == nullptr) {
        std::cout << "Invalid position!" << std::endl;
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

int LinkedList::searchByValue(int value) {
    Node* current = head;
    int position = 1;
    while (current != nullptr && current->data != value) {
        current = current->next;
        position++;
    }

    if (current == nullptr) {
        return -1;
    }

    return position;
}

int LinkedList::searchByPosition(int position) {
    if (position <= 0) {
        return -1;
    }

    Node* current = head;
    int currentPosition = 1;
    while (current != nullptr && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }

    if (current == nullptr) {
        return -1;
    }

    return current->data;
}

void LinkedList::print() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void LinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

bool LinkedList::isEmpty() {
    return head == nullptr;
}
