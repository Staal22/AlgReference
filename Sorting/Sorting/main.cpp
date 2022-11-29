#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Interfaces/Stringable.h"
#include "SortingAlgClasses/SelectionSort.h"

#include "SortingAlgClasses/QuickSort.h"
#include "SortingAlgClasses/VectorHelpers.h"

#include "../../LinkedLists/LinkedLists/LinkedList.h"
#include "SortingAlgClasses/HeapSort/HeapSort.h"
#include "SortingAlgClasses/MergeSort/MergeSort.h"


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
    bool operator <(const SomeScalarClass& rhs) const {
        return value < rhs.value;
    }

    bool operator >(const SomeScalarClass& rhs) const {
        return value > rhs.value;
    }

    bool operator <=(const SomeScalarClass& rhs) const {
        return value <= rhs.value;
    }


    SomeScalarClass operator +(const SomeScalarClass& rhs) const {
        return SomeScalarClass(value + rhs.value);
    }

    std::string ToString() override {

        size_t a = std::to_string(value).find(".");
        return std::to_string(value).substr(0, a + 2);
    }

    // overloading the std::cout << operator! This way we can super easily debug it to console
    // note: we cannot do this directly in the class, becouse when oveloading normale we can only choose the operator and the *right* side if the operator (where left is the class)
    // therefore we have to link it to a seperate overload (hence the friend keyword)
    friend std::ostream& operator<<(std::ostream& os, SomeScalarClass& s);

};

std::ostream& operator<<(std::ostream& os, SomeScalarClass& s) {
    os << s.value;
    return os;
}

// SELECTION SORT
// ----------------------------------------------------------
void ShowSelectionSortLinkedList(const std::vector<int> mainList) {
    LinkedList<SomeScalarClass> list = LinkedList<SomeScalarClass>();

    for (int i = 0; i < mainList.size(); ++i) {
        list.InsertAtBack(SomeScalarClass(mainList[i]));
    }

    SelectionSort(list);

    std::cout << list << std::endl;
    return;
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


// QUICK SORT
// ----------------------------------------------------------
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

void ShowQuickSortLinkedList(const std::vector<int>& mainList) {

    LinkedList<SomeScalarClass> someBingusList{};
    for (int i = 0; i < mainList.size(); ++i) {
        someBingusList.InsertAtBack(SomeScalarClass(mainList[i]));
    }
    // std::cout << someBingusList.Size() << std::endl;
    // std::cout << someBingusList << std::endl;

    QuickSort<SomeScalarClass>(someBingusList, 0, someBingusList.Size() - 1);

    std::cout << someBingusList << std::endl;
    // PrintVector<SomeScalarClass>(someBingusList);
}

// MERGE SORT
// ----------------------------------------------------------
void ShowMergeSort(const std::vector<int>& mainList) {
    std::vector<SomeScalarClass> someBingusList{};
    for (int i = 0; i < mainList.size(); ++i) {
        someBingusList.push_back(SomeScalarClass(mainList[i]));
    }
    MergeSort(someBingusList, 0, someBingusList.size() - 1);

    PrintVector(someBingusList);
}

void ShowMergeSortLinkedList(const std::vector<int>& mainList) {
    
    LinkedList<SomeScalarClass> someBingusList{};
    for (int i = 0; i < mainList.size(); ++i) {
        someBingusList.InsertAtBack(SomeScalarClass(mainList[i]));
    }
    MergeSort(someBingusList, 0, someBingusList.Size() - 1);

    std::cout << someBingusList << std::endl;
}

// HEAP SORT
// ----------------------------------------------------------
void ShowHeapSort(const std::vector<int>& mainList) {
    std::vector<SomeScalarClass> someBingusList{};
    for (int i = 0; i < mainList.size(); ++i) {
        someBingusList.push_back(SomeScalarClass(mainList[i]));
    }

    HeapSort(someBingusList);
    PrintVector(someBingusList);
}

void ShowHeapSortLinkedList(const std::vector<int>& mainList) {
    
    LinkedList<SomeScalarClass> someBingusList{};
    for (int i = 0; i < mainList.size(); ++i) {
        someBingusList.InsertAtBack(SomeScalarClass(mainList[i]));
    }
    HeapSort(someBingusList);

    std::cout << someBingusList << std::endl;
}

// MAIN
// ----------------------------------------------------------
int main(int argc, char* argv[]) {
    // showing off operator overloading
    // SomeScalarClass ssc1(15);
    // SomeScalarClass ssc2(30);
    // SomeScalarClass ssc3 = ssc1 + ssc2;
    //
    // std::cout << ssc1.ToString() << std::endl << ssc2.ToString() << std::endl << ssc3.ToString() << std::endl;
    // return 0;

    /*
    int begin = 0;
    std::vector<int> lis = {1,2,5,6,1000, 50,52,100, 105};
    int end = lis.size()-1; 
    int mid = begin + (end - begin) / 2;
    Merge(lis, 0, mid, end);
    
    for (int i = 0; i < lis.size(); ++i) {
        std::cout << lis[i] << " ";
    }
    std::cout << std::endl;
    // return 0;
    */

    // std::vector<int> lis2 = {1000, 1, 7, 5};
    // MergeSort(lis2, 0, lis2.size()-1);

    
    
    std::vector<int> list = {1000, 1, 7, 5, 12, -4, 69, 100, 99, 2, 0, 4, 3, 4, -692};
    
    std::cout << "SELECTION SORT : " << std::endl;
    ShowSelectionSort(list);
    ShowSelectionSortLinkedList(list);
    std::cout << std::endl;
    
    std::cout << "QUICK SORT : " << std::endl;
    ShowQuickSort(list);
    ShowQuickSortLinkedList(list);
    std::cout << std::endl;
    
    std::cout << "MERGE SORT : " << std::endl;
    ShowMergeSort(list);
    ShowMergeSortLinkedList(list);
    std::cout << std::endl;

    std::cout << "HEAP SORT : " << std::endl;
    ShowHeapSort(list);
    ShowHeapSortLinkedList(list);
    std::cout << std::endl;
    return 0;

    QuickSortPartition(list, 0, list.size() - 1);
    PrintVector(list);
    QuickSortPartition(list, 0, 2);
    PrintVector(list);
    QuickSortPartition(list, 0, 1);
    PrintVector(list);
    return 0;
}
