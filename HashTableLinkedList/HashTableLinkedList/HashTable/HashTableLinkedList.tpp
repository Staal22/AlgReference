

#include <assert.h>
#include "../Initializer.h"



template<typename K>
int HashFunction(K key, const int& tableSize) {
    assert(std::is_arithmetic_v<K>);
    return static_cast<int>(key) % tableSize;
}

template<>
int HashFunction<std::string>(std::string key, const int& tableSize) {
    // if key is text, get sum of ascii values mod capacity
    size_t sum{};
    for (const char i : key) {
        sum += static_cast<size_t>(i);
    }
    return sum % tableSize;
}

template<typename K, typename T>
bool HashTableLinkedList<K, T>::IsEmpty() const {
    int sum{};
    for (int i = 0; i < tableSize; ++i) {
        
        const LinkedList<std::pair<K, T>>& cell = table[i];
        
        // std::cout << cell.Size() << std::endl;
        if (cell.Size() != 0) {
            return false;   
        }
    }

    return true;
}

// template<typename K, typename T>
// int HashTableLinkedList<K, T>::HashFunction(K key) const {
    // assert(std::is_arithmetic_v<K>);
    // return static_cast<int>(key) % tableSize;
// }


template<typename K, typename T>
void HashTableLinkedList<K, T>::InsertItem(K key, T value) {
    int hash = HashFunction<K>(key, tableSize);
    
    bool bKeyExists = false;
    Node<std::pair<K, T>>* searchNode = table[hash].GetNodeAt(0);
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
        table[hash].InsertAtBack(std::pair<K, T>(key, value));
    }
    
}

template<typename K, typename T>
void HashTableLinkedList<K, T>::RemoveItem(K key) {
    int hash = HashFunction<K>(key, tableSize);
    
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

template<typename K, typename T>
T HashTableLinkedList<K, T>::SearchTable(K key) {
    int hash = HashFunction<K>(key, tableSize);
    LinkedList<std::pair<K, T>> list = table[hash];

    Node<std::pair<K, T>>* searchNode = list.GetNodeAt(0);
    while (searchNode != nullptr) {
        if (searchNode->data.first == key) {
            return searchNode->data.second;
        }
    }

    Initializer<T> def{};
    return def.t;
}

template<typename K, typename T>
void HashTableLinkedList<K, T>::Print() {
    for (int i = 0; i < tableSize; ++i) {
        auto& cell = table[i];
        for (int j = 0; j < cell.Size(); ++j) {
            std::cout << "Group: " << i << " Key: " << cell[j].first << " Value: " << cell[j].second << std::endl;
        }
    }
}

