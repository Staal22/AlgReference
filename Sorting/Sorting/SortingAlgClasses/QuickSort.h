#pragma once
#include <vector>

#include "../../../LinkedLists/LinkedLists/LinkedList.h"

// NON TEMPLATE
// ---------------------------------------------
int QuickSortPartition(std::vector<int>& list, int start, int end);

void QuickSort(std::vector<int>& list, int start, int end);

// TEMPLATE VECTOR
// ---------------------------------------------
template<typename T>
int QuickSortPartition(std::vector<T>& list, int start, int end);

template<typename T>
void QuickSort(std::vector<T>& list, int start, int end);

// TEMPLATE LINKEDLIST
// ----------------------------------------------
template <typename T>
int QuickSortPartition(LinkedList<T>& list, int start, int end);

template<typename T>
void QuickSort(LinkedList<T>& list, int start, int end);



#include "QuickSort.tpp"