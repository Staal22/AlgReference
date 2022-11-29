#pragma once
#include <iomanip>
#include <iostream>

#include "../Interfaces/Stringable.h"


template <typename T>
void PrintVector(std::vector<T>& list) {
    // forces the T to inherit from i stringable
    static_assert(std::is_base_of<IStringable, T>::value, "T must inherit from IStringable");

    std::cout << std::setprecision(12);
    
    for (int i = 0; i < list.size(); ++i) {
        std::cout << list[i].ToString() << " ";
        // std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}
