#pragma once
#include <iostream>
#include "Node.h"



class Queue {
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

    void Enqueue(int data) {
        Node* newNode = new Node(data);
        // some checks
        if (head == nullptr && tail == nullptr) {
            tail = head = newNode;
            size++;
            return;
        }

        Node* prevHead = head;
        
        // if the queue is not empty
        newNode->next = head;
        head = newNode;

        // setting prev
        
        prevHead->prev = head;
        
        size++;
    }

    void Dequeue() {
        if (head == nullptr && tail == nullptr) {
            return;
        }

        Node* deleteTail = tail;
        tail = tail->prev;
        delete deleteTail;

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
