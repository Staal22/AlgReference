#pragma once
#include <queue>

template<typename T, typename  Container, typename  Comparator>
class PriorityQueueDerived : public std::priority_queue<T, Container, Comparator> {
public:
    // PriorityQueueDerived(Comparator comparator) :std::priority_queue<T, Container, Comparator>(comparator) {
        
    //  }
    
    
    PriorityQueueDerived(Comparator comparator) : std::priority_queue<T, Container, Comparator>(comparator) {
        
    }
    Container& GetContainer() {
        return this->c;
    }
};

