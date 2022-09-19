#include <cstring>
#include <iostream>

void OldWay();

int main(int argc, char* argv[]) {
    // OldWay();
    // return 0;
    // memcpy way
    char arr[] = "Hello World";

    char targetArray[sizeof(arr)/sizeof(arr[0])];
    int offset = 6;
    memcpy(targetArray, arr + offset, sizeof(char) * offset);
    memcpy(targetArray + offset, arr, sizeof(char) * offset);
    for (int i = 0; i < sizeof(targetArray); ++i) {
        std::cout << targetArray[i];
    }
    std::cout << std::endl;

    return 0;
}

void OldWay() {
    char arr[] = "HelloWorld";
    int offset = 5;
    for (int i = 0; i < 5; ++i) {
        char temp = arr[i];
        arr[i] = arr[i + offset];
        arr[i + offset] = temp;
    }

    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i];
    }
    std::cout << std::endl;
}
