#pragma once
#include <vector>

void SelectionSort(std::vector<int>& list);

template<typename T>
void SelectionSort(std::vector<T>& list);

#include "SelectionSort.tpp"