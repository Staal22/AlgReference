#pragma once

template<typename T>
NodeT<T>::NodeT(T _data) {
    data = _data;
}

template<typename T>
void NodeT<T>::Insert(T newData) {
    if (newData < data) {
        if (left != nullptr) {
            left->Insert(newData);
            return;
        }
        //else
        {
            // we are at leaf
            left = new NodeT<T>(newData);
            return;
        }
    }
    else {
        if (right != nullptr) {
            right->Insert(newData);
            return;
        }
        else {
            // we are at leaf
            right = new NodeT<T>(newData);
            return;
        }
    }
}

template<typename T>
T NodeT<T>::Find(T dataToFind) {
    if (dataToFind == data)
        return data;
    
    if (left != nullptr && dataToFind < data)
        return left->Find(dataToFind);
    
    if (right != nullptr && dataToFind > data)
        return right->Find(dataToFind);
    // if we do not have the node
    return NULL;
}

template<typename T>
void NodeT<T>::Clear() {
    if (left != nullptr) {
        left->Clear();
    }
    if (right != nullptr) {
        right->Clear();
    }
    delete this;
}

template <typename T>
NodeT<T>* NodeT<T>::Delete(T dataToDelete, NodeT<T>* current) {
    if (current == nullptr) {
        return nullptr;  
    }

    if (dataToDelete < current->data) {
        current->left =  Delete(dataToDelete, current->left);
    }
    else if (dataToDelete > current->data) {
        current->right =  Delete(dataToDelete, current->right);
    }
    else  { // current->data == dataToDelete
        if (current->left == nullptr) {
            NodeT<T>* temp = current->right;
            delete current;
            return temp;
        }
        else if (current->right == nullptr) {
            NodeT<T>* temp = current->left;
            delete current;
            return temp;
        }
        // if current have two children and is equal dataToDelete
        NodeT<T>* minValNode = GetMinValueNode(current->right);
        current->data = minValNode->data;

        current->right = Delete(minValNode->data, current->right);
    }
    return current;
}


template<typename T>
int NodeT<T>::Size() {
    int size{};
    GetActualSize(size);
    return size;
}

template<typename T>
void NodeT<T>::ToStringInOrder(std::string& someText) {
    std::string retVal = "";
    if (left != nullptr) {
        left->ToStringInOrder(someText);
    }
    someText += std::to_string(data) + " ";
    if (right != nullptr) {
        right->ToStringInOrder(someText);
    }
}

template<typename T>
void NodeT<T>::ToStringPreOrder(std::string& someText) {
    std::string retVal = "";
    someText += std::to_string(data) + " ";
    if (left != nullptr) {
        left->ToStringPreOrder(someText);   
    }
    if (right != nullptr) {
        right->ToStringPreOrder(someText);
    }
}

template<typename T>
void NodeT<T>::ToStringPostOrder(std::string& someText) {
        
    std::string retVal = "";
    if (left != nullptr) {
        left->ToStringPostOrder(someText);   
    }
    if (right != nullptr) {
        right->ToStringPostOrder(someText);
    }
    someText += std::to_string(data) + " ";
}

template<typename T>
void NodeT<T>::PrintTree() {
    // find all data and sort them into depth
    std::vector<std::pair<int, T>> depths{}; // pair<depth, value>
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
                // padding -= std::to_string(depths[j].second).size();
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

template<typename T>
void NodeT<T>::GetActualSize(int& size) {
    size++;
    if (left != nullptr) {
        left->GetActualSize(size);
    }
    if (right != nullptr) {
        right->GetActualSize(size);
    }
}

template<typename T>
void NodeT<T>::GetDepthValuePair(std::vector<std::pair<int, T>>& listt, int depth) {
    if (left != nullptr) {
        left->GetDepthValuePair(listt, depth+1);
    }
    listt.push_back(std::pair<int,T>(depth, data));
    if (right != nullptr) {
        right->GetDepthValuePair(listt, depth +1);
    }
}
template<typename T>
NodeT<T>* NodeT<T>::GetMinValueNode(NodeT<T>* current) {
    if (current->left != nullptr) {
        return GetMinValueNode(current->left);
    }
    return current;

    
}
