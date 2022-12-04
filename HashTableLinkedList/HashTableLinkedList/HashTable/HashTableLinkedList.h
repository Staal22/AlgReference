#pragma once
#include "../../../LinkedLists/LinkedLists/LinkedList.h"
// #include "../../../Sorting/Sorting/Interfaces/Stringable.h"

template<typename K>
int HashFunction(K key, const int& tableSize);


template<>
int HashFunction<std::string>(std::string key, const int& tableSize);



/**
 * \brief TemplateClass that can store diffentrent types of values and with different key types
 * \tparam K key
 * \tparam T value to store
 */
template <typename K, typename T>
class HashTableLinkedList {
    // makes sure the class derives from the IStringable interface (so we force it to use ToString();
    // static_assert(std::is_base_of<IStringable, T>::value, "T must inherit from IStringable");
private:
    static const int tableSize = 10;
    LinkedList<std::pair<K, T>> table[tableSize]; // fist is key second is value
public:
    bool IsEmpty() const;
    //int HashFunction(K key) const;

    void InsertItem(K key, T value);
    void RemoveItem(K key);
    T SearchTable(K key);
    void Print();


};

#include "HashTableLinkedList.tpp"
