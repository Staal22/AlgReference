#pragma once

class Node {
public:
    Node(int data) {
        this->data = data;
    }

    Node* next = nullptr;
    Node* prev = nullptr;
    int data = 0;
};
