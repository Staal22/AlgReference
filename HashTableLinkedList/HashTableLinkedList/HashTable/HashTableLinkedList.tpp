

template <typename T>
bool HashTableLinkedList<T>::IsEmpty() const {
    int sum{};
    for (int i = 0; i < tableSize; ++i) {
        auto cell = table[i];
        // std::cout << cell.Size() << std::endl;
        if (cell.Size() != 0) {
            return false;   
        }
    }

    return true;
}

template <typename T>
int HashTableLinkedList<T>::HashFunction(int key) {
}

template <typename T>
void HashTableLinkedList<T>::InsertItem(int key, T value) {
}

template <typename T>
void HashTableLinkedList<T>::RemoveItem(int key) {
}

template <typename T>
std::string HashTableLinkedList<T>::SearchTable(int key) {
}

template <typename T>
void HashTableLinkedList<T>::Print() {
}
