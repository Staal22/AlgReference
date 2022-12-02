#pragma once

#include <string>
#include <vector>
#include <iostream>

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

    void ToStringInOrder(std::string& someText);

    void ToStringPreOrder(std::string& someText);

    void ToStringPostOrder(std::string& someText);

    void PrintTree();

private:
    void GetActualSize(int& size);

    void GetDepthValuePair(std::vector<std::pair<int,int>>& list, int depth);
};

template<typename T>
class NodeT {
public:
    NodeT* l{};
    NodeT* r{};
    T data{};

    NodeT(T _data);

    void Insert(T newData);

    T Find(T dataToFind);

    void Clear();

    NodeT<T>* Delete(T dataToDelete, NodeT<T>* current);

    
    
    int Size();

    void ToStringInOrder(std::string& someText);

    void ToStringPreOrder(std::string& someText);

    void ToStringPostOrder(std::string& someText);

    void PrintTree();

private:
    void GetActualSize(int& size);

    void GetDepthValuePair(std::vector<std::pair<int,T>>& listt, int depth);

    NodeT<T>* GetMinValueNode(NodeT<T>* current);
};

#include "Node.tpp"