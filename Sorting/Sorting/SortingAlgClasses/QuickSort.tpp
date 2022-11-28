#pragma once

// TEMPLATE VECTOR
// --------------------------------
template<typename T>
int QuickSortPartition(std::vector<T>& list, int start, int end) {
    
    int pivotIndex = end;
    
    int fli = start;
    int fri = end - 1;
    
    while (fli <= fri) {
        // left
        while (list[fli] < list[pivotIndex] && fli <= end - 1) {
            fli++;
        }

        while (list[fri] > list[pivotIndex] && fri > start) {
            fri--;
        }

        if (fli < fri) {
            
            std::swap(list[fli], list[fri]);
            // PrintVector(list);
        }
        else {
            break;
        }
    }

    // if (list[fli] > list[pivotIndex] ) {
        std::swap(list[pivotIndex], list[fli]);
    // }
    
    return fli;
}


template<typename T>
void QuickSort(std::vector<T>& list, int start, int end) {
    
    // exit condition
    if (start >= end) {
        return;
    }

    
    // partition
    int pivot = QuickSortPartition(list, start, end);
    
    QuickSort<T>(list, start, pivot - 1);
    QuickSort<T>(list, pivot + 1, end);
}

// TEMPLATE LINKEDLIST
// -----------------------------------
template <typename T>
int QuickSortPartition(LinkedList<T>& list, int start, int end) {
    
    int pivotIndex = end;
    
    int fli = start;
    int fri = end - 1;
    
    while (fli <= fri) {
        // left
        while (list[fli] < list[pivotIndex] && fli <= end - 1) {
            fli++;
        }

        while (list[fri] > list[pivotIndex] && fri > start) {
            fri--;
        }

        if (fli < fri) {
            list.Swap(fli, fri);
            // std::swap(list[fli], list[fri]);
            // PrintVector(list);
        }
        else {
            break;
        }
    }

    // if (list[fli] > list[pivotIndex] ) {
    list.Swap(pivotIndex, fli);
        // std::swap(list[pivotIndex], list[fli]);
    // }
    
    return fli;
}


template<typename T>
void QuickSort(LinkedList<T>& list, int start, int end) {
    // exit condition
    if (start >= end) {
        return;
    }

    
    // partition
    int pivot = QuickSortPartition(list, start, end);
    
    QuickSort<T>(list, start, pivot - 1);
    QuickSort<T>(list, pivot + 1, end);
}

