#include "HashTable.h"
#include <iostream>

bool HashTable::IsEmpty() const {
    int sum{};
    for (int i = 0; i < hashGroups; ++i) {
        sum += table[i].size();
    }
    if (!sum) {
        return true;
    }
    return false;
}

int HashTable::HashFunction(int key) {
    return key % hashGroups; // key 905 -> function will return 5
}

void HashTable::InsertItem(int key, std::string value) {
    int hashValue = HashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = std::begin(cell);
    bool bKeyExists = false; // TODO
    for (; bItr != std::end(cell); bItr++) {
        if (bItr->first == key) {
            bKeyExists = true;
            bItr->second = value;
            std::cout << "WARNING : key exists. Value replaced" << std::endl;
            break;
        }
    }

    if (!bKeyExists) {
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable::RemoveItem(int key) {
    int hashValue = HashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = std::begin(cell);
    bool bKeyExists = false; // TODO
    for (; bItr != std::end(cell); bItr++) {
        if (bItr->first == key) {
            bKeyExists = true;
            bItr = cell.erase(bItr);
            std::cout << "INFO : Pair Removed" << std::endl;
            break;
        }
    }

    if (!bKeyExists) {
        std::cout << "WARNING : Key not found. Pair not removed." << std::endl;
    }
}

std::string HashTable::SearchTable(int key) {
    return "awdaw";
}



void HashTable::Print() {
    for (int i = 0; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            std::cout << "INFO : Key: " << bItr->first << " Value: " << bItr->second << std::endl;
        }
    }
    return;
}
