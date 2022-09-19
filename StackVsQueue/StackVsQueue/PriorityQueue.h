
#include <iostream>

// 0 is least priority, inf is max priority
class PriorityNode {
public:
    PriorityNode(int newData, unsigned int newPriority) {
        data  = newData;
        priority = newPriority;
    }
    
    PriorityNode* next = nullptr;
    PriorityNode* prev = nullptr;
    int data = -1;
    unsigned int priority = 0;
};

class PriorityQueue {
public:
    PriorityNode* head = nullptr;
    PriorityNode* tail = nullptr;
    int size = 0;

    void Enqueue(int data, unsigned int priority) {
        PriorityNode* newNode = new PriorityNode(data, priority);
        // some checks
        if (head == nullptr && tail == nullptr) {
            tail = head = newNode;
            size++;
            return;
        }
        
        // if the queue is not empty

        // find the appropiate location to enqueue the element
        PriorityNode* searchNode = head;
        bool bInserted = false;
        for (int i = 0; i < size; ++i) {
            if (newNode->priority >= searchNode->priority )
            {
                PriorityNode* oldPrev = searchNode->prev;
                
                searchNode->prev = newNode;
                newNode->next = searchNode;
                newNode->prev = oldPrev;
                
                if (oldPrev != nullptr) { // prev exists, not head
                    oldPrev->next = newNode;
                }
                else { // prev aexists, was head
                    head = newNode;
                }
                bInserted = true;
                break;
            }
            searchNode = searchNode->next;
        }

        if (!bInserted) { // newNode priority is smallest 
            PriorityNode* oldTail = tail;
            oldTail->next = newNode;
            newNode->prev = oldTail;
            newNode->next = nullptr;
            tail = newNode;
        }
        
        size++;
    }

    void Dequeue() {
        if (head == nullptr && tail == nullptr) {
            return;
        }

        PriorityNode* deleteTail = tail;
        tail = tail->prev;
        delete deleteTail;

        size--;
    }

    void PrintList() {
        PriorityNode* searchNode;

        searchNode = head;
        for (int i = 0; i < size; ++i) {
            std::cout << searchNode->data << ' ' << searchNode->priority << " | ";

            
            searchNode = searchNode->next;
        }
        std::cout << std::endl;
    }

private:
};
