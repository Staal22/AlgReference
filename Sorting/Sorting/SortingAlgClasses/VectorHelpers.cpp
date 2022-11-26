#include "VectorHelpers.h"

#include <iostream>


void PrintVector(std::vector<int>& list) {
    for (int i = 0; i < list.size(); ++i) {
        std::cout << list[i] << " "; 
    }
    std::cout << std:: endl;
}

void PrintVector(std::vector<int>& list, int start, int end) {
    for (int i = start; i < end - 1; ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}
