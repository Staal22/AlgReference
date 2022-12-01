#pragma once
#include <queue>

template<typename T, typename  Container, typename  Comparator>
class PriorityQueueDerived : public std::priority_queue<T, Container, Comparator> {
public:
    Container& GetContainer();
};

