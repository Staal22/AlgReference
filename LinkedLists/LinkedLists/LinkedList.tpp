// #include "LinkedList.h"

// the way to define a static const variable to a class.
template <class T>
const std::string LinkedList<T>::k_outOfRangeMessage  = "ERROR_INDEX_OUT_OF_RANGE : ";

template <class T>
LinkedList<T>::LinkedList() {
    jaw = nullptr;
}

template <class T>
T& LinkedList<T>::At(const int& index) {
    Node<T>* node = jaw;
    int i = 0;
    while (node != nullptr) {

        if (i == index) {
            return node->data;
        }

        node = node->next;
        i++;
    }


}

template <class T>
Node<T>* LinkedList<T>::GetNodeAt(const int& index) {
    Node<T>* current = jaw;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current;
}

template <class T>
void LinkedList<T>::InsertAtFront(T data) {
    Node<T>* new_node = new Node<T>();

    new_node->data = data;
    new_node->next = jaw;
    jaw = new_node;
}

template <class T>
void LinkedList<T>::InsertAtIndex(int index, T data) {
    if (IsOutOfRange(index)) {
        std::cout << k_outOfRangeMessage << index <<std::endl;
    }
        

    
    // if we are head
    if (index == 0) {
        InsertAtFront(data);
        return;
    }


    Node<T>* searchNode = jaw;
    int i = 0;
    while (searchNode != nullptr) {
        if (i + 1 == index) {
            Node<T>* insertNode = new Node<T>;
            insertNode->data = data;
            insertNode->next = searchNode->next; // this can be null :) so it works if its the last index

            searchNode->next = insertNode;

            //are we the head?
            return;
        }

        searchNode = searchNode->next;
        i++;
    }


}

template <class T>
void LinkedList<T>::RemoveAtIndex(int index) {
    

    
    if (index == 0) {
        Node<T>* toRemove = GetNodeAt(0);
        jaw = toRemove->next;
        delete toRemove;
    }
        
        
    Node<T>* pre = GetNodeAt(index - 1);
    Node<T>* toRemove = pre->next;
    pre->next = pre->next->next;
           
    delete toRemove;
}

template <class T>
void LinkedList<T>::printList() {
    Node<T>* start = jaw;
    while (start->next != nullptr) {
        std::cout << start->data << " ";
        start = start->next;
    }

    std::cout << start->data;
    std::cout << std::endl;
}

template <class T>
void LinkedList<T>::printListReverse() {
    int size = Size();
    int index = size - 1;

    for (int j = index; j >= 0; --j) {
        std::cout << At(j) << ' ';
    }


    std::cout << std::endl;
}

template <class T>
int LinkedList<T>::Size() {

    Node<T>* searchNode = jaw;
    int size = 0;
    while (searchNode != nullptr) {

        if (searchNode->next == nullptr) {
            return size + 1;
        }

        size++;
        searchNode = searchNode->next;
    }

    return -1;
}

template <class T>
void LinkedList<T>::Swap(int iIndex, int jIndex) {
    if (iIndex == jIndex) {
        return;
    }

    
    T idata = At(iIndex);
    T jdata = At(jIndex);

    InsertAtIndex(jIndex, idata);
    InsertAtIndex(iIndex, jdata);

    RemoveAtIndex(jIndex + 2);
    RemoveAtIndex(iIndex + 1);
    

    
    
    
    
    // inserting after

    // GetNodeAt(iIndex - 1)->next
    // At(0).
        
        
}

template <class T>
bool LinkedList<T>::IsOutOfRange(int index) {
    if (index < 0) 
        return true;
        
    int size = Size();
    if (index >= size)         
        return true;

    return false;
}
