#pragma once

#include <string>
#include <vector>

class Node {
public:
    Node* l{};
    Node* r{};
    int data{};

    Node(int _data);

    void Insert(int newData);

    int Find(int number);

    void Clear();

    int Size();

    /*
    // void ToString() {
    //     std::cout << data << std::endl;
    //     if (l != nullptr)
    //         l->ToString();
    //     if (r != nullptr)
    //         r->ToString();
    // }
    */

    void ToStringInOrder(std::string& someText);

    void ToStringPreOrder(std::string& someText);

    void ToStringPostOrder(std::string& someText);

    void PrintTree();

private:
    void GetActualSize(int& size);

    void GetDepthValuePair(std::vector<std::pair<int,int>>& list, int depth);
};
