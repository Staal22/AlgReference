#pragma once
#include "../../../LinkedLists/LinkedLists/LinkedList.h"
// #include "../../../Sorting/Sorting/Interfaces/Stringable.h"


template<typename T>
class HashTableLinkedList {
    // makes sure the class derives from the IStringable interface (so we force it to use ToString();
    // static_assert(std::is_base_of<IStringable, T>::value, "T must inherit from IStringable");
private:
    static const int tableSize = 10;
    LinkedList<std::pair<int, T>> table[tableSize];
public:
    bool IsEmpty() const;
    int HashFunction(int key);
    void InsertItem(int key, T value);
    void RemoveItem(int key);
    T SearchTable(int key); // TODO implement properly
    void Print();
    
};

#include "HashTableLinkedList.tpp"
