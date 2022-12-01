#include "PriorityQueueDerived.h"
using namespace std;
template <typename T, typename Container, typename Comparator>
Container& PriorityQueueDerived<T, Container, Comparator>::GetContainer() {
    return this->c;
}
