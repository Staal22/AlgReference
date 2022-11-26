#pragma once
#include <iostream>
#include <string>
#include <utility>

class HashTableOpenAdressing {
private:
    const static int numSlots = 10;
    const static int EMPTY_INDEX = -1;
    std::pair<int, std::string> slots[numSlots];
public:
    HashTableOpenAdressing() {
        for (int i = 0; i < numSlots; ++i) {
            slots[i].first = EMPTY_INDEX;
        }
    }

    int FindHashOfKey(int key) {
        for (int i = 0; i < numSlots; ++i) {
            if (slots[i].first == key) {
                return i;
            }
        }
        
        return EMPTY_INDEX;
    }
    
    int FindOpenSlot(int startSlot, int key) {
        for (int i = 0; i < numSlots; ++i) {
            int index = (startSlot + i) % numSlots;
            
            if (slots[index].first == EMPTY_INDEX) { // if not -1, its clear
                return index;
                break;
            }
        }

        return EMPTY_INDEX; // return -1 if array is full!
    }

    std::string Query(int key) {
        int hash = GetHash(key);
        if (slots[hash].first == key) {
            return slots[hash].second;
        }


        // if we did not find
        hash = FindHashOfKey(key);
        if (hash != EMPTY_INDEX) {
            return slots[hash].second;
        }

        return "N/A";
    }
    
    void Insert(int key, std::string value) {
        if (FindHashOfKey(key) != EMPTY_INDEX) {
            std::cout << "WARNING: Key allredy exists... ABORTING" << std::endl;
            return;
        }
        
        int hash = GetHash(key);
        int openSlotIndex = FindOpenSlot(hash, key);
        
        if (openSlotIndex != EMPTY_INDEX) {
            slots[openSlotIndex].first = key;
            slots[openSlotIndex].second = value;
        }
        else {
            std::cout << "WARNING: Hash Table full! Did NOT insert data" << std::endl;
        }
    }

    void Remove(int key) {
        bool keyHash = FindHashOfKey(key);
        if (keyHash != EMPTY_INDEX) { // key exists
            int hash = GetHash(key);
            slots[hash].first = EMPTY_INDEX;
            slots[hash].second = std::string{}; // this is not nececery but its here for redundancy
        }
        else { // key does not exist
            std::cout << "WARNING: Key does not exit..." << std::endl;
        }
    }

    int GetHash(int key) {
        return key % numSlots;
    }

    bool IsEmpty() {
        int sum = 0;
        for (int i = 0; i < numSlots; ++i) {
            sum += slots[i].second.size();
        }

        if (sum != 0) {
            return false;
        }
        return true;
    }

    void Print() {
        for (int i = 0; i < numSlots; ++i) {
            std::cout << "Key: "<< slots[i].first << " Value: " << slots[i].second << std::endl;
        }
    }
};
