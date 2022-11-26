#pragma once
#include <vector>


void PrintVector(std::vector<int>& list);

int QuickSortPartition(std::vector<int>& list, int start, int end);

void QuickSort(std::vector<int>& list, int start, int end);
