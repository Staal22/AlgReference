#pragma once
#include <vector>



int QuickSortPartition(std::vector<int>& list, int start, int end);

void QuickSort(std::vector<int>& list, int start, int end);

template<typename T>
int QuickSortPartition(std::vector<T>& list, int start, int end);

template<typename T>
void QuickSort(std::vector<T>& list, int start, int end);

#include "QuickSort.tpp"