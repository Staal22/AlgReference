

#include <vector>

#include "QuickSort.h"

void SelectionSort(std::vector<int>& list) {
    for (int i = 0; i < list.size(); ++i) {
        int smallIndex = i;
        for (int j = i; j < list.size(); ++j) {
            if (list[j] < list[smallIndex]) {
                smallIndex = j;
            }
        }

        std::swap(list[i], list[smallIndex]);
        // PrintVector(list);
    }
}


