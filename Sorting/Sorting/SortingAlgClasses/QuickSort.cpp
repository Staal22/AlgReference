#include "QuickSort.h"

#include <iostream>
#include <vector>

#include "VectorHelpers.h"


int QuickSortPartition(std::vector<int>& list, int start, int end) {

    // if (end - start == 1) {
        // if (list[start] > list[end]) {
            // std::swap(list[start], list[end]);
        // }

        // return start;
    // }
    
    // chooses pivot as end
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
            PrintVector(list);
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

void QuickSort(std::vector<int>& list, int start, int end) {
    // exit condition
    if (start >= end) {
        return;
    }

    
    // partition
    int pivot = QuickSortPartition(list, start, end);
    
    QuickSort(list, start, pivot - 1);
    QuickSort(list, pivot + 1, end);
    
}





// from geeks for geeks
/*

// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}

int main()
{

    int arr[] = { 9, 3, 4, 2, 1, 8 };
    int n = 6;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

 */
