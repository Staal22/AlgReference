#pragma once
#include <iostream>


template <typename T>
class Node {
public:
    T data;
    Node<T>* next = nullptr;

    template<typename  U>
    friend std::ostream& operator<<(std::ostream& os, const Node<U>& n);
};

template <class T>
class LinkedList {
private:
    Node<T>* jaw;
    static const std::string k_outOfRangeMessage;
public:
    LinkedList();

    T& At(const int& index) const;

    Node<T>* GetNodeAt(const int& index);
    
    T& operator[](const int& index) {
        return At(index);
    }
    
    void InsertAtFront(T data);

    void InsertAtBack(T data);

    void InsertAtIndex(int index, T data);

    void RemoveAtIndex(int index);


    
    void printList();

    void printListReverse();

    int Size() const;

    void Swap(int iIndex, int jIndex);

    bool IsOutOfRange(int index);

    template<class U>
    friend std::ostream& operator << (std::ostream& os, const LinkedList<U>& lt);
};

#include "LinkedList.tpp"   
