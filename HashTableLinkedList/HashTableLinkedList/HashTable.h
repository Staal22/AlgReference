#pragma once
#include <iostream>
#include <vector>

#include "../../LinkedLists/LinkedLists/LinkedList.h"


class HashTable {
public:
    int bucketSize;
    std::vector<LinkedList<int>> bucketLists;
    

    HashTable(int value) :bucketSize(1) , bucketLists(value)
    {
        this->bucketSize = value;
        std::vector<int> (bucketSize);

    }

    void insertItem(int key)
    {
        int index = hashFunction(key);
        std::cout << " index : " << index << "Key : " << key << std::endl;
        bucketLists[index].InsertAtFront(key);
    }

    
    int hashFunction(int x) const {
        int ret = x % bucketSize;
        return ret;
    }

    void displayHash() {
        for (int i = 0; i < bucketSize; i++) {
            std::cout << i;
        }
        std::cout << std::endl;
        for (int i = 0; i < bucketSize; i++) {
            std::cout << "i : " << i << std::endl;
            bucketLists[i].printList();
        }
    }

    


private:
};
