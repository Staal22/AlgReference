#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "SortingAlgClasses/SelectionSort.h"

#include "SortingAlgClasses/QuickSort.h"
#include "SortingAlgClasses/VectorHelpers.h"

#include "../../LinkedLists/LinkedLists/LinkedList.h"
#include "SortingAlgClasses/HeapSort/HeapSort.h"
#include "SortingAlgClasses/MergeSort/MergeSort.h"
#include "SomeScalarClass.h"

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

    // SomeScalarClass* ref = new SomeScalarClass(69);
    
    // SomeScalarClass s(1.112515f);
    // s.next = ref;
    // SomeScalarClass b(s);

    // std::cout << s.value << " " << s.next  << std::endl;
    // std::cout << b.value << " " << b.next << std::endl;
     
    // return 0;

    
    
    
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
