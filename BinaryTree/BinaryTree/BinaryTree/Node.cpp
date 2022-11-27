#include "Node.h"


#include <iostream>
#include <list>
#include <conio.h>

Node::Node(int _data) {
    data = _data;
}

void Node::Insert(int newData) {
    if (newData < data) {
        if (l != nullptr) {
            l->Insert(newData);
            return;
        }
        else {
            // we are at leaf
            l = new Node(newData);
            return;
        }
    }
    else {
        if (r != nullptr) {
            r->Insert(newData);
            return;
        }
        else {
            // we are at leaf
            r = new Node(newData);
            return;
        }
    }
}

int Node::Find(int number) {
    if (l != nullptr && number < data) {
        return l->Find(number);
    }
    if (r != nullptr && number > data) {
        return r->Find(number);
    }
    return data;
}

void Node::Clear() {
    if (l != nullptr) {
        l->Clear();
    }
    if (r != nullptr) {
        r->Clear();
    }
    delete this;
}

int Node::Size() {
    int size{};
    GetActualSize(size);
    return size;
}

void Node::ToStringInOrder(std::string& someText) {
    std::string retVal = "";
    if (l != nullptr) {
        l->ToStringInOrder(someText);
    }
    someText += std::to_string(data) + " ";
    if (r != nullptr) {
        r->ToStringInOrder(someText);
    }
}

void Node::ToStringPreOrder(std::string& someText) {
    std::string retVal = "";
    someText += std::to_string(data) + " ";
    if (l != nullptr) {
        l->ToStringPreOrder(someText);   
    }
    if (r != nullptr) {
        r->ToStringPreOrder(someText);
    }
}

void Node::ToStringPostOrder(std::string& someText) {
        
    std::string retVal = "";
    if (l != nullptr) {
        l->ToStringPostOrder(someText);   
    }
    if (r != nullptr) {
        r->ToStringPostOrder(someText);
    }
    someText += std::to_string(data) + " ";
}

void Node::PrintTree() {
    // find all data and sort them into depth
    std::vector<std::pair<int, int>> depths{}; // pair<depth, value>
    GetDepthValuePair(depths, 0);

        
        
    // find max depth
    int maxDepth{};
    for (auto pair : depths) {
        if (pair.first > maxDepth) 
            maxDepth = pair.first;
    }

    for (int i = 0; i < maxDepth + 1; ++i) {
        for (int j = 0; j < depths.size(); ++j) {
            int padding = 3;
            if (depths[j].first == i) {
                padding -= std::to_string(depths[j].second).size();
                std::cout << depths[j].second;
            }
            for (int x = 0; x < padding; ++x) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    // for (int i = 0; i < depths.size(); ++i) {
    //     std::cout << "DEPTH: " << depths[i].first << " DATA: " << depths[i].second << std::endl;
    // }
        
}

void Node::GetActualSize(int& size) {
    size++;
    if (l != nullptr) {
        l->GetActualSize(size);
    }
    if (r != nullptr) {
        r->GetActualSize(size);
    }
}

void Node::GetDepthValuePair(std::vector<std::pair<int, int>>& list, int depth) {
    if (l != nullptr) {
        l->GetDepthValuePair(list, depth+1);
    }
    list.push_back(std::pair<int,int>(depth, data));
    if (r != nullptr) {
        r->GetDepthValuePair(list, depth +1);
    }
}
