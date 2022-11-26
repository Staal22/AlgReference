
#include <iostream>
#include <vector>

#include "SortingAlgClasses/QuickSort.h"


int main(int argc, char* argv[])
{
    std::vector<int> list = {1000, 1,7,5,12, -4, 69, 100, 99,2,0,4, 3, 4, -692};
    QuickSort(list, 0, list.size() - 1);
    PrintVector(list);
    return 0;
    
    QuickSortPartition(list, 0, list.size() - 1);
    PrintVector(list);
    QuickSortPartition(list,0,2);
    PrintVector(list);
    QuickSortPartition(list,0,1);
    PrintVector(list);
    return 0;
}
