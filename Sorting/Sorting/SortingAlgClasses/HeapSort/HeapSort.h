#pragma once
#include <vector>
#include <algorithm>


// TEMPLATE VECTOR
// ------------------------
template<typename T>
void PrintHeap(std::vector<int> list);

/**
 * \brief hepifies from the given start index of i, remember this does not make a max heap. It only does so if certain conditions are met:\n
 * All other elements after i in the heap structure are a maxHeap, and only the element at index is not.
 * \tparam T type in vector
 * \param list list with elements
 * \param i index we start from
 */
template<typename T>
void Heapify(std::vector<T>& list, int i, int size);

template<typename T>
void BuildMaxHeap(std::vector<T>& list);

template<typename T>
void HeapSort(std::vector<T>& list);

// TEMPLATE LINKED LIST
// ------------------------

template<typename T>
void PrintHeap(LinkedList<int> list);

/**
 * \brief hepifies from the given start index of i, remember this does not make a max heap. It only does so if certain conditions are met:\n
 * All other elements after i in the heap structure are a maxHeap, and only the element at index is not.
 * \tparam T type in vector
 * \param list list with elements
 * \param i index we start from
 */
template<typename T>
void Heapify(LinkedList<T>& list, int i, int size);

template<typename T>
void BuildMaxHeap(LinkedList<T>& list);

template<typename T>
void HeapSort(LinkedList<T>& list);
#include "HeapSort.tpp"