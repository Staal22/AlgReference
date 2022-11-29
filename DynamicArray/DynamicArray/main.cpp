
#include "DynamicArray/DynamicArray.h"


int main(int argc, char* argv[])
{
    
    DynamicArray<int> vec{1,7,1,3,63,124};

    // vec.PushBack(16);
    // vec.PushBack(69);
    // vec.PushBack(1259);

    // vec.InsertAtIndex(2, 42);
    // vec.InsertAtIndex(5, 42);
    // vec.InsertAtIndex(7, 42);

    std::cout << vec << std::endl;
    std::cout << "Capacity : " << vec.Capacity() << " Size : " << vec.Size() << std::endl;
    return 0;
    for (int i = 0; i < vec.Size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Capacity : " << vec.Capacity() << " Size : " << vec.Size() << std::endl;
    return 0;
}
