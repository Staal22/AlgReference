

#include "../Initializer.h"

template <typename T>
bool HashTableLinkedList<T>::IsEmpty() const {
    int sum{};
    for (int i = 0; i < tableSize; ++i) {
        
        const LinkedList<std::pair<int, T>>& cell = table[i];
        
        // std::cout << cell.Size() << std::endl;
        if (cell.Size() != 0) {
            return false;   
        }
    }

    return true;
}

template <typename T>
int HashTableLinkedList<T>::HashFunction(int key) {
    return key % tableSize;
}

template <typename T>
void HashTableLinkedList<T>::InsertItem(int key, T value) {
    int hash = HashFunction(key);
    
    bool bKeyExists = false;
    Node<std::pair<int, T>>* searchNode = table[hash].GetNodeAt(0);
    while (searchNode != nullptr) {
        if (searchNode->data.first == key) {
            bKeyExists = true;
            searchNode->data.second = value;
            std::cout << "WARNING : key exists. Value replaced" << std::endl;
            break;
        }
        searchNode = searchNode->next;
    }

    if (!bKeyExists) {
        table[hash].InsertAtBack(std::pair<int, T>(key, value));
    }
    
}

template <typename T>
void HashTableLinkedList<T>::RemoveItem(int key) {
    int hash = HashFunction(key);
    
    bool bKeyExists = false;
    Node<std::pair<int, T>>* searchNode = table[hash].GetNodeAt(0);
    int index = 0;
    while (searchNode != nullptr) {
        if (searchNode->data.first == key) {
            bKeyExists = true;
            // searchNode->data.second = value;
            std::cout << "WARNING : key exists. Deleting pair" << std::endl;
            break;
        }
        searchNode = searchNode->next;
        index++;
    }

    if (bKeyExists) {
        LinkedList<std::pair<int, T>>& list = table[hash];
        list.RemoveAtIndex(index);
    }
}

template <typename T>
T HashTableLinkedList<T>::SearchTable(int key) {
    int hash = HashFunction(key);
    LinkedList<std::pair<int, T>> list = table[hash];

    Node<std::pair<int, T>>* searchNode = list.GetNodeAt(0);
    while (searchNode != nullptr) {
        if (searchNode->data.first == key) {
            return searchNode->data.second;
        }
    }

    Initializer<T> def{};
    return def.t;
}

template <typename T>
void HashTableLinkedList<T>::Print() {
    for (int i = 0; i < tableSize; ++i) {
        auto& cell = table[i];
        for (int j = 0; j < cell.Size(); ++j) {
            std::cout << "Group: " << i << " Key: " << cell[j].first << " Value: " << cell[j].second << std::endl;
        }
    }
}
