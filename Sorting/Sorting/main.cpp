
#include <iostream>
#include <vector>

#include "SortingAlgClasses/QuickSort.h"

void PrintVector(std::vector<int>& list) {
    for (int i = 0; i < list.size(); ++i) {
        std::cout << list[i] << " "; 
    }
    std::cout << std:: endl;
}

int main(int argc, char* argv[])
{
    std::vector<int> list = {1,7,5,12,8,0,4};
    PrintVector(list);
    QuickSortPartition(list, 0, list.size() - 1);
    PrintVector(list);   
    return 0;
}
