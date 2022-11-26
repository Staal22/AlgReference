#pragma once

template<typename T>
auto SelectionSort(std::vector<T>& list) -> void {
    for (int i = 0; i < list.size(); ++i) {
        int smallIndex = i;
        for (int j = i; j < list.size(); ++j) {
            if (list[j] < list[smallIndex]) {
                smallIndex = j;
            }
        }

        std::swap(list[i], list[smallIndex]);
        // PrintVector(list);
    }
}
