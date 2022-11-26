#pragma once
#include <vector>

void PrintVector(std::vector<int>& list);

void PrintVector(std::vector<int>& list, int start, int end);

template<typename T>
void PrintVector(std::vector<T>& list);

#include "VectorHelpers.tpp"

