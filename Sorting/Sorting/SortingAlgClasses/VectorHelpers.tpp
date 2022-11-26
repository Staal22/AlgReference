#pragma once
#include <iostream>

#include "../Interfaces/Stringable.h"


template <typename T>
void PrintVector(std::vector<T>& list) {
    static_assert(std::is_base_of<IStringable, T>::value, "T must inherit from list");

    for (int i = 0; i < list.size(); ++i) {
        std::cout << list[i].ToString() << " ";
    }
    std::cout << std::endl;
}
