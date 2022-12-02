#pragma once

template<typename T>
NodeT<T>::NodeT(T _data) {
    data = _data;
}

template<typename T>
void NodeT<T>::Insert(T newData) {
    if (newData < data) {
        if (l != nullptr) {
            l->Insert(newData);
            return;
        }
        else {
            // we are at leaf
            l = new NodeT<T>(newData);
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
            r = new NodeT<T>(newData);
            return;
        }
    }
}

template<typename T>
T NodeT<T>::Find(T dataToFind) {
    if (dataToFind == data)
        return data;
    
    if (l != nullptr && dataToFind < data)
        return l->Find(dataToFind);
    
    if (r != nullptr && dataToFind > data)
        return r->Find(dataToFind);
    // if we do not have the node
    return NULL;
}

template<typename T>
void NodeT<T>::Clear() {
    if (l != nullptr) {
        l->Clear();
    }
    if (r != nullptr) {
        r->Clear();
    }
    delete this;
}

template <typename T>
NodeT<T>* NodeT<T>::Delete(T dataToDelete, NodeT<T>* current) {
    if (current == nullptr) {
        return nullptr;  
    }

    if (dataToDelete < current->data) {
        current->l =  Delete(dataToDelete, current->l);
    }
    else if (dataToDelete > current->data) {
        current->r =  Delete(dataToDelete, current->r);
    }
    else  { // current->data == dataToDelete
        if (current->l == nullptr) {
            NodeT<T>* temp = current->r;
            delete current;
            return temp;
        }
        else if (current->r == nullptr) {
            NodeT<T>* temp = current->l;
            delete current;
            return temp;
        }
        // if current have two children and is equal dataToDelete
        NodeT<T>* minValNode = GetMinValueNode(current->r);
        current->data = minValNode->data;

        current->r = Delete(minValNode->data, current->r);
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
    if (l != nullptr) {
        l->ToStringInOrder(someText);
    }
    someText += std::to_string(data) + " ";
    if (r != nullptr) {
        r->ToStringInOrder(someText);
    }
}

template<typename T>
void NodeT<T>::ToStringPreOrder(std::string& someText) {
    std::string retVal = "";
    someText += std::to_string(data) + " ";
    if (l != nullptr) {
        l->ToStringPreOrder(someText);   
    }
    if (r != nullptr) {
        r->ToStringPreOrder(someText);
    }
}

template<typename T>
void NodeT<T>::ToStringPostOrder(std::string& someText) {
        
    std::string retVal = "";
    if (l != nullptr) {
        l->ToStringPostOrder(someText);   
    }
    if (r != nullptr) {
        r->ToStringPostOrder(someText);
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
    if (l != nullptr) {
        l->GetActualSize(size);
    }
    if (r != nullptr) {
        r->GetActualSize(size);
    }
}

template<typename T>
void NodeT<T>::GetDepthValuePair(std::vector<std::pair<int, T>>& listt, int depth) {
    if (l != nullptr) {
        l->GetDepthValuePair(listt, depth+1);
    }
    listt.push_back(std::pair<int,T>(depth, data));
    if (r != nullptr) {
        r->GetDepthValuePair(listt, depth +1);
    }
}
template<typename T>
NodeT<T>* NodeT<T>::GetMinValueNode(NodeT<T>* current) {
    if (current->l != nullptr) {
        return GetMinValueNode(current->l);
    }
    return current;

    
}
