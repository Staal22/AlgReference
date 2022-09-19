#pragma once
#include <iostream>

#include "Node.h"


class Stack {
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

    void Push(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr && tail == nullptr) {
            head = tail = newNode;
            size++;
            return;
        }

        tail->next = newNode; // Old tail -> tail
        newNode->prev = tail; // Old tail -><- tail
        tail = newNode; //setting actual tail to new node
        size++;
    }

    void Pop() {
        if (size == 0)
            return;
        Node* oldTail = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete oldTail;

        size--;
    }

    void PrintList() {
        Node* searchNode;

        searchNode = head;
        for (int i = 0; i < size; ++i) {
            std::cout << searchNode->data << ' ';
            searchNode = searchNode->next;
        }
        std::cout << std::endl;
    }

private:
};
