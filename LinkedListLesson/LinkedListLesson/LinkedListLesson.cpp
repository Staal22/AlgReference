#include <algorithm>
#include <forward_list>
#include <iostream>
#include <vector>

#include "Member.h"
#include "Timer.h"

template <typename T>
class Node {
public:
    T data;
    Node<T>* next = nullptr;
};

template <class T>
class LinkedList {
private:
    Node<T>* jaw;
public:
    LinkedList() {
        jaw = nullptr;
    }

    T& At(const int& index) {
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

    T& operator[](const int& index) {
        return At(index);
    }

    void InsertAtFront(T data) {
        Node<T>* new_node = new Node<T>();

        new_node->data = data;
        new_node->next = jaw;
        jaw = new_node;
    }


    void InsertAtIndex(int index, T data) {
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


    void printList() {
        Node<T>* start = jaw;
        while (start->next != nullptr) {
            std::cout << start->data << " ";
            start = start->next;
        }

        std::cout << start->data;
        std::cout << std::endl;
    }

    void printListReverse() {
        int size = Size();
        int index = size - 1;

        for (int j = index; j >= 0; --j) {
            std::cout << At(j) << ' ';
        }


        std::cout << std::endl;
    }

    int Size() {

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
};


void task1();

void task2();

void task3();

int main() {
    // task1();
    // task2();

    // task3();
    // return 0;


    LinkedList<int> list = LinkedList<int>();
    list.InsertAtFront(5);
    list.InsertAtFront(5);
    list.InsertAtFront(5);
    list.InsertAtFront(5);
    list.InsertAtIndex(3, 2);
    list.printList();
    list.printListReverse();
    return 0;
}

void task1() {

    int size = 10;
    int* list[10];
    list[0] = new int(42);
    list[1] = new int(1);
    list[2] = new int(90);
    list[3] = new int(-2);
    list[4] = new int(56);
    list[5] = new int(1);
    list[6] = new int(12);
    list[7] = new int(101);
    list[8] = new int(73);
    list[9] = new int(25);


    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (*list[j] > *list[j + 1]) {
                // spawn
                int* tempadrees = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tempadrees;
            }
        }
    }

    // prints
    for (int i = 0; i < size; ++i) {
        std::cout << *list[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < size; ++i) {
        delete list[i];
    }
}

void task2() {
    int size = 10000;
    //array
    int* array = new int[10000];
    for (int i = 0; i < size; ++i) {
        array[i] = i;
    }

    Timer arrayTimer = Timer();
    for (int i = 0; i < size; ++i) {
        array[i] = array[i] * 2;
        // std::cout << array[i] << ' ';
    }

    long long arrayTime = arrayTimer.Stop();
    std::cout << std::endl;
    std::cout << "array took " << arrayTime << " ms" << std::endl;

    //vector
    //--------------
    std::vector<int> vectorArr(size);
    //setting values
    for (int i = 0; i < size; ++i) {
        vectorArr[i] = i;
    }

    for (int i = 0; i < size; ++i) {
        vectorArr[i] = vectorArr[i] * 2;
    }

    Timer vectorTimer = Timer();
    for (int i = 0; i < size; ++i) {
        vectorArr[i] = vectorArr[i] * 2;
        // std::cout << vectorArr[i] << ' ';
    }

    long long vectorTime = vectorTimer.Stop();

    std::cout << std::endl;
    std::cout << "vector took " << vectorTime << " ms" << std::endl;


    // linked list
    // -------------------------
    LinkedList<int> linkedArr;
    //setting values
    for (int i = 0; i < size; ++i) {
        linkedArr.InsertAtFront(i);
    }

    // printint and mult

    Timer linkedTimer = Timer();
    for (int i = 0; i < size; ++i) {
        linkedArr[i] = linkedArr[i] * 2;
        // std::cout << linkedArr[i] << ' ';

    }

    long long linkedTime = linkedTimer.Stop();
    std::cout << std::endl;
    std::cout << "linkedList took " << linkedTime << " ms" << std::endl;


}

void task3() {
    std::vector<Member> members(5);
    members[0].name = "Bjarne";
    members[0].age = 21;
    members[1].name = "Arne";
    members[1].age = 22;
    members[2].name = "Stjarne";
    members[2].age = 23;
    members[3].name = "Ajrne";
    members[3].age = 26;
    members[4].name = "Varje";
    members[4].age = 100;

    std::sort(members.begin(), members.end(), [](Member a, Member b)
    {
        return a.age < b.age;
    });

    for (int i = 0; i < members.size(); ++i) {
        std::cout << members[i].name << " " << members[i].age << std::endl;
    }


}
