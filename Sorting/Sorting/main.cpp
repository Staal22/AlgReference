#include <iostream>
#include <string>
#include <vector>

#include "Interfaces/Stringable.h"
#include "SortingAlgClasses/SelectionSort.h"

#include "SortingAlgClasses/QuickSort.h"
#include "SortingAlgClasses/VectorHelpers.h"

#include "../../LinkedLists/LinkedLists/LinkedList.h"


class SomeScalarClass : public IStringable {
public:
    // SomeScalarClass() = default;
    SomeScalarClass() {
        value = 0;
    }
    SomeScalarClass(float f) {
        value = f;
    }

    float value{};

    // used for sorting
    bool operator < (const SomeScalarClass& rhs) const {
        return value < rhs.value;
    }

    bool operator > (const SomeScalarClass& rhs) const {
        return value > rhs.value;
    }


    SomeScalarClass operator + (const SomeScalarClass& rhs) const {
        return SomeScalarClass(value + rhs.value);
    }

    std::string ToString() override {

        size_t a = std::to_string(value).find(".");
        return std::to_string(value).substr(0,a + 2);
    }

};

// struct Comparator{
//     bool operator < (knockOffFLoat l, knockOffFLoat r) {
//         return l.value < r.value;
//     }  
//     bool operator > (knockOffFLoat l, knockOffFLoat r) {
//         return l.value > r.value;
//     }  
// };

void ShowSelectionSortLinkedList(const std::vector<int> mainList) {
    LinkedList<SomeScalarClass> list = LinkedList<SomeScalarClass>();
    
    for (int i = 0; i < mainList.size(); ++i) {
        list.InsertAtBack(SomeScalarClass(mainList[i]));
    }

    SelectionSort(list);

    for (int i = 0; i < list.Size(); ++i) {
        std::cout << list[i].ToString() << " ";
    }
}

void ShowSelectionSort(const std::vector<int> mainList) {
    
    std::vector<SomeScalarClass> someBingusList{};
    for (int i = 0; i < mainList.size(); ++i) {
        someBingusList.push_back(SomeScalarClass(mainList[i]));
    }

    SelectionSort<SomeScalarClass>(someBingusList);

    PrintVector<SomeScalarClass>(someBingusList);
    // for (int i = 0; i < someBingusList.size(); ++i) {
        // std::cout << someBingusList[i].value << " ";
    // }
    // std::cout << std::endl;
}

void ShowQuickSort(const std::vector<int>& mainList) {

    std::vector<SomeScalarClass> someBingusList{};
    for (int i = 0; i < mainList.size(); ++i) {
        someBingusList.push_back(SomeScalarClass(mainList[i]));
    }

    QuickSort<SomeScalarClass>(someBingusList, 0, mainList.size() - 1);


    PrintVector<SomeScalarClass>(someBingusList);
    // for (int i = 0; i < someBingusList.size(); ++i) {
        // std::cout << someBingusList[i].value << " ";
    // }
    // std::cout << std::endl;
}

void ShowMergeSort(const std::vector<int>& mainList) {
    std::vector<SomeScalarClass> someBingusList{};
    for (int i = 0; i < mainList.size(); ++i) {
        someBingusList.push_back(SomeScalarClass(mainList[i]));
    }

    
}

int main(int argc, char* argv[]) {
    // showing off operator overloading
    // SomeScalarClass ssc1(15);
    // SomeScalarClass ssc2(30);
    // SomeScalarClass ssc3 = ssc1 + ssc2;
    //
    // std::cout << ssc1.ToString() << std::endl << ssc2.ToString() << std::endl << ssc3.ToString() << std::endl;
    // return 0;

    std::vector<int> list = {1000, 1, 7, 5, 12, -4, 69, 100, 99, 2, 0, 4, 3, 4, -692};

    // ShowSelectionSort(list);


    // ShowQuickSort(list);
    ShowSelectionSortLinkedList(list);
    return 0;

    // QuickSort(list, 0, list.size() - 1);
    SelectionSort(list);
    PrintVector(list);

    return 0;

    QuickSortPartition(list, 0, list.size() - 1);
    PrintVector(list);
    QuickSortPartition(list, 0, 2);
    PrintVector(list);
    QuickSortPartition(list, 0, 1);
    PrintVector(list);
    return 0;
}
