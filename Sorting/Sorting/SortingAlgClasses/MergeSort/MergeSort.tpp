#pragma once

template<typename T>
void MergeSort(std::vector<T>& list, int begin, int end) {
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;

    MergeSort(list, begin, mid);
    MergeSort(list, mid+1, end);
    
    Merge(list, begin, mid, end);
}


template<typename T>
std::vector<T> Merge(std::vector<T>& list, int begin, int mid, int end) {
    int leftSize = mid + 1 - begin;
    int rightSize = end - mid;

    std::vector<T>  leftList(leftSize);
    std::vector<T>  rightList(leftSize);

    // copy data to lists
    for (int i = 0; i < leftSize; ++i) {
        leftList[i] = list[begin + i];
    }
    for (int i = 0; i < rightSize; ++i) {
        rightList[i] = list[mid + 1 + i];
    }

    int indexLeft  = 0;
    int indexRight = 0;
    int indexMerge = 0;

    // merge left right array into main
    while (indexLeft < leftSize && indexRight && rightSize) {
        if (leftList[indexLeft]) {
            
        }
    }
}


