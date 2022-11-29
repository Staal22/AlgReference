#pragma once



// TEMPLATE VECTOR
// ------------------------
template<typename T>
void PrintHeap(std::vector<int> list) {
    std::cout << list[0] << std::endl;
    
    int cut = 2;
    for (int i = 1; i < list.size(); ++i) {
        std::cout << list[i] << " ";
        if (cut <= i) {
            std::cout << std::endl;
            cut =cut* 2 + 2;
        }
    }
}

template<typename T>
void Heapify(std::vector<T>& list, int i, int size) {
    // find the children on a given node (look up heapify for better explenation / illustrations)
    int left = 2 * i + 1;
    int right = 2 * i + 2;


    // find largest of the three (root, left or right)
    
    if (left >= size)
        left = i;
    
    if (right >= size)
        right = i;
    
    // im doing some coding skateboard tricks here, this is a TERRIBLE way to code it, as its not easily understandable (though is really efficient >:) )
    auto biggest = [&list](const int l, const int r) {return list[l] < list[r];    };
    int max = std::max({left, right, i}, biggest);

    if (max != i) {
        std::swap(list[max], list[i]);

        Heapify(list, max, size);       
    }
}

template<typename T>
void BuildMaxHeap(std::vector<T>& list) {
    int size = list.size();
    for (int i = list.size()/2 -1; i >=0; i--) {
        Heapify(list, i, size);
    }
}

template<typename T>
void HeapSort(std::vector<T>& list) {
    BuildMaxHeap(list);

    
    for (int i = list.size()-1; i >= 0; i--) {
        std::swap(list[0], list[i]);

        Heapify(list, 0, i);
    }
    
}

// TEMPLATE LINKED LIST
// ------------------------template<typename T>
void PrintHeap(LinkedList<int> list) {
    std::cout << list[0] << std::endl;
    
    int cut = 2;
    for (int i = 1; i < list.Size(); ++i) {
        std::cout << list[i] << " ";
        if (cut <= i) {
            std::cout << std::endl;
            cut =cut* 2 + 2;
        }
    }
}

template<typename T>
void Heapify(LinkedList<T>& list, int i, int size) {
    // find the children on a given node (look up heapify for better explenation / illustrations)
    int left = 2 * i + 1;
    int right = 2 * i + 2;


    // find largest of the three (root, left or right)
    
    if (left >= size)
        left = i;
    
    if (right >= size)
        right = i;

    
    // im doing some skateboard coding tricks here, this is a TERRIBLE way to code it, as its not easily understandable (though is really efficient >:) )
    auto biggest = [&list](const int l, const int r) {return list[l] < list[r];    };
    int max = std::max({left, right, i}, biggest);

    if (max != i) {
        std::swap(list[max], list[i]);

        Heapify(list, max, size);       
    }
}

template<typename T>
void BuildMaxHeap(LinkedList<T>& list) {
    int size = list.Size();
    for (int i = list.Size()/2 -1; i >=0; i--) {
        Heapify(list, i, size);
    }
}

template<typename T>
void HeapSort(LinkedList<T>& list) {
    BuildMaxHeap(list);

    
    for (int i = list.Size()-1; i >= 0; i--) {
        std::swap(list[0], list[i]);

        Heapify(list, 0, i);
    }
    
}

