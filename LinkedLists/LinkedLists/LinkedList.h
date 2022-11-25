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
    LinkedList();

    T& At(const int& index);

    Node<T>* GetNodeAt(const int& index);
    
    T& operator[](const int& index) {
        return At(index);
    }
    
    void InsertAtFront(T data);

    void InsertAtIndex(int index, T data);

    void RemoveAtIndex(int index) {
        
    }
    
    void printList();

    void printListReverse();

    int Size();

    void Swap(int iIndex, int jIndex);
};



#include "LinkedList.tpp"   
