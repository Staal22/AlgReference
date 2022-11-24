#include "QuickSort.h"
#include <vector>

int QuickSortPartition(std::vector<int>& list, int start, int end) {

    
    // chooses pivot as end
    int pivotIndex = end;
    
    int fli = start;
    int fri = end - 1;
    
    while (fli < fri) {
        // left
        while (list[fli] < list[pivotIndex]) {
            fli++;
        }

        while (list[fri] > list[pivotIndex]) {
            fri--;
        }

        if (fli < fri) {
            std::swap(list[fli], list[fri]);
        }
        else {
            break;
        }
    }
    
    return pivotIndex;
}

void QuickSort(std::vector<int>& list, int start, int end) {

    
}

