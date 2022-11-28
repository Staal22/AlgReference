#pragma once
#include "../VectorHelpers.h"


// VECTOR
// -------------------------------------
template <typename T>
void MergeSort(std::vector<T>& list, int begin, int end) {
    if (begin >= end) {
        return;
    }

    int mid = begin + (end - begin) / 2;

    MergeSort(list, begin, mid);
    MergeSort(list, mid + 1, end);
    Merge(list, begin, mid, end);
}

// std::vector<int> lis1 = {1,5, 54, 70, 1,2, 5, 12};
// Merge(lis1, 0, 3, lis1.size() - 1);
template <typename T>
void Merge(std::vector<T>& list, int begin, int mid, int end) {
    int leftSize = mid + 1 - begin;
    int rightSize = end - mid;

    std::vector<T> leftList(leftSize);
    std::vector<T> rightList(leftSize);

    // copy data to lists
    for (int i = 0; i < leftSize; ++i) {
        leftList[i] = list[begin + i];
    }
    for (int i = 0; i < rightSize; ++i) {
        rightList[i] = list[mid + 1 + i];
    }

    int indexLeft = 0;
    int indexRight = 0;
    int indexMerge = begin;

    // merge left right array into main
    while (indexLeft < leftSize && indexRight < rightSize) {
        if (leftList[indexLeft] <= rightList[indexRight]) {
            list[indexMerge] = leftList[indexLeft];
            indexLeft++;
        }
        else {
            list[indexMerge] = rightList[indexRight];
            indexRight++;
        }
        indexMerge++;
    }

    while (indexLeft < leftSize) {
        list[indexMerge] = leftList[indexLeft];
        indexLeft++;
        indexMerge++;
    }
    while (indexRight < rightSize) {
        list[indexMerge] = rightList[indexRight];
        indexRight++;
        indexMerge++;
    }

}

// LINKED LIST
// -------------------------------------------------------
template <typename T>
void MergeSort(LinkedList<T>& list, int begin, int end) {
    if (begin >= end) {
        return;
    }

    int mid = begin + (end - begin) / 2;

    MergeSort(list, begin, mid);
    MergeSort(list, mid + 1, end);
    Merge(list, begin, mid, end);
}

// std::vector<int> lis1 = {1,5, 54, 70, 1,2, 5, 12};
// Merge(lis1, 0, 3, lis1.size() - 1);
template <typename T>
void Merge(LinkedList<T>& list, int begin, int mid, int end) {
    int leftSize = mid + 1 - begin;
    int rightSize = end - mid;

    std::vector<T> leftList(leftSize);
    std::vector<T> rightList(leftSize);

    // copy data to lists
    for (int i = 0; i < leftSize; ++i) {
        leftList[i] = list[begin + i];
    }
    for (int i = 0; i < rightSize; ++i) {
        rightList[i] = list[mid + 1 + i];
    }

    int indexLeft = 0;
    int indexRight = 0;
    int indexMerge = begin;

    // merge left right array into main
    while (indexLeft < leftSize && indexRight < rightSize) {
        if (leftList[indexLeft] <= rightList[indexRight]) {
            list[indexMerge] = leftList[indexLeft];
            indexLeft++;
        }
        else {
            list[indexMerge] = rightList[indexRight];
            indexRight++;
        }
        indexMerge++;
    }

    while (indexLeft < leftSize) {
        list[indexMerge] = leftList[indexLeft];
        indexLeft++;
        indexMerge++;
    }
    while (indexRight < rightSize) {
        list[indexMerge] = rightList[indexRight];
        indexRight++;
        indexMerge++;
    }

}
