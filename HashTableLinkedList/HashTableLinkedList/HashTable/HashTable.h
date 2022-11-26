// reference https://www.youtube.com/watch?v=2_3fR-k-LzI
#pragma once
#include <list>
#include <string>

class HashTable {
public:
    static const int hashGroups = 10;
    std::list<std::pair<int, std::string>> table[hashGroups]; // list 1 = index 0, list 2 = index 1 ...

public:
    bool IsEmpty() const;
    int HashFunction(int key);
    void InsertItem(int key, std::string value);
    void RemoveItem(int key);
    std::string SearchTable(int key); // TODO implement properly
    void Print();
};




