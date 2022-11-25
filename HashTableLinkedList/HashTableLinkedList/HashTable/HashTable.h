#pragma once
#include <list>
#include <string>

class HashTable {
private:
    static const int hashGroups = 10;
    std::list<std::pair<int, std::string>> table[hashGroups]; // list 1 = index 0, list 2 = index 1 ...
    
public:
    bool IsEmpty() const;
    int HasFunction(int key);
    void InsertItem(int key, std::string value);
    void RemoveItem(int key);
    std::string SearchTable(int key);
    void Print();
};

bool HashTable::IsEmpty() const {
    for (int i = 0; i < hashGroups; ++i) {
        if (table[i].size()) {
            
        }
    }
}




