#pragma once
#include <vector>

template<typename T>
std::vector<T> MergeSort(std::vector<T>& list);

template<typename T>
std::vector<T> Merge(std::vector<T>& list, int begin, int mid, int end);

#include "MergeSort.tpp"