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
template<typename T>
void SelectionSort(LinkedList<T>& list) {
    for (int i = 0; i < list.Size(); ++i) {
        int smallIndex = i;
        for (int j = i; j < list.Size(); ++j) {
            if (list[j] < list[smallIndex]) {
                smallIndex = j;
            }
        }

        list.Swap(i, smallIndex);
        // std::swap(list[i], list[smallIndex]);
        // PrintVector(list);
    }
}
