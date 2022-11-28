#pragma once
#include <vector>

template<typename T>
void MergeSort(std::vector<T>& list, int begin, int end);

template<typename T>
void Merge(std::vector<T>& list, int begin, int mid, int end);

#include "MergeSort.tpp"