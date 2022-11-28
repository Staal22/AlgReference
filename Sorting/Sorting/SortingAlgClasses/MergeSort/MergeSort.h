#pragma once
#include <vector>

#include "../../../../LinkedLists/LinkedLists/LinkedList.h"

template<typename T>
void MergeSort(std::vector<T>& list, int begin, int end);

template<typename T>
void Merge(std::vector<T>& list, int begin, int mid, int end);

template<typename T>
void MergeSort(LinkedList<T>& list, int begin, int end);

template<typename T>
void Merge(LinkedList<T>& list, int begin, int mid, int end);

#include "MergeSort.tpp"