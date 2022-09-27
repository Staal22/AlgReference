#pragma once
#include <iostream>


template <typename T>
class Node {
public:
    T data;
    Node<T>* next = nullptr;
};

template <class T>
class LinkedList {
private:
    Node<T>* jaw;
public:
    LinkedList() {
        jaw = nullptr;
    }

    T& At(const int& index) {
        Node<T>* node = jaw;
        int i = 0;
        while (node != nullptr) {

            if (i == index) {
                return node->data;
            }

            node = node->next;
            i++;
        }


    }

    T& operator[](const int& index) {
        return At(index);
    }

    void InsertAtFront(T data) {
        Node<T>* new_node = new Node<T>();

        new_node->data = data;
        new_node->next = jaw;
        jaw = new_node;
    }


    void InsertAtIndex(int index, T data) {
        // if we are head
        if (index == 0) {
            InsertAtFront(data);
            return;
        }


        Node<T>* searchNode = jaw;
        int i = 0;
        while (searchNode != nullptr) {
            if (i + 1 == index) {
                Node<T>* insertNode = new Node<T>;
                insertNode->data = data;
                insertNode->next = searchNode->next; // this can be null :) so it works if its the last index

                searchNode->next = insertNode;

                //are we the head?
                return;
            }

            searchNode = searchNode->next;
            i++;
        }


    }


    void printList() {
        Node<T>* start = jaw;
        while (start->next != nullptr) {
            std::cout << start->data << " ";
            start = start->next;
        }

        std::cout << start->data;
        std::cout << std::endl;
    }

    void printListReverse() {
        int size = Size();
        int index = size - 1;

        for (int j = index; j >= 0; --j) {
            std::cout << At(j) << ' ';
        }


        std::cout << std::endl;
    }

    int Size() {

        Node<T>* searchNode = jaw;
        int size = 0;
        while (searchNode != nullptr) {

            if (searchNode->next == nullptr) {
                return size + 1;
            }

            size++;
            searchNode = searchNode->next;
        }

        return -1;
    }
};