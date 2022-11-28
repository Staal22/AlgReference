#pragma once
#include <vector>

#include "../../../LinkedLists/LinkedLists/LinkedList.h"

void SelectionSort(std::vector<int>& list);

template<typename T>
void SelectionSort(std::vector<T>& list);

template<typename T>
void SelectionSort(LinkedList<T>& list);
#include "SelectionSort.tpp"