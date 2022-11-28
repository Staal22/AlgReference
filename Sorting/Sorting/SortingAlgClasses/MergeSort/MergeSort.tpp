#pragma once
#include "../VectorHelpers.h"

template <typename T>
void MergeSort(std::vector<T>& list, int begin, int end) {
    if (begin >= end) {
        std::cout << list[begin] <<  std::endl;
        return;
    }

    int mid = begin + (end - begin) / 2;

    for (int i = 0; i < end - begin + 1; ++i) {
        std::cout << list[begin + i] << " ";
    }
    std::cout << std::endl;
    MergeSort(list, begin, mid);
    MergeSort(list, mid + 1, end);


    std::cout << "BEFOREMERGE : ";
    for (int i = 0; i < list.size(); ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
    Merge(list, begin, mid, end);
    std::cout << "AFTERMERGE : ";
    for (int i = 0; i < list.size(); ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
    return;
    std::cout << std::endl;
}

// std::vector<int> lis1 = {1,5, 54, 70, 1,2, 5, 12};
// Merge(lis1, 0, 3, lis1.size() - 1);
template <typename T>
void Merge(std::vector<T>& list, int begin, int mid, int end) {
    int leftSize = mid + 1 - begin;
    int rightSize = end - mid;

    std::vector<T> leftList(leftSize);
    std::vector<T> rightList(leftSize);

    std::cout << "LEFTARR : ";
    // copy data to lists
    for (int i = 0; i < leftSize; ++i) {
        leftList[i] = list[begin + i];
        std::cout << list[begin + i]<< " ";
    }
    std::cout << std::endl;
    std::cout << "RIGHTARR : ";
    for (int i = 0; i < rightSize; ++i) {
        rightList[i] = list[mid + 1 + i];
        std::cout << list[mid + 1 + i] << " ";
    }
    std::cout << std::endl;

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

    std::cout << "COMBINDED : ";
    for (int i = 0; i < end - begin + 1; ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}
