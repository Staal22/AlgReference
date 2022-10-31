#include <iostream>
#include <string>
#include <vector>

class Node {
public:
    Node* l{};
    Node* r{};
    int data{};

    Node(int _data) {
        data = _data;
    }

    void Insert(int newData) {
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

    int Find(int number) {
        if (l != nullptr && number < data) {
            return l->Find(number);
        }
        if (r != nullptr && number > data) {
            return r->Find(number);
        }
        return data;
    }
    
    void Clear() {
        if (l != nullptr) {
            l->Clear();
        }
        if (r != nullptr) {
            r->Clear();
        }
        delete this;
    }
    
    void ToString() {
        std::cout << data << std::endl;
        if (l != nullptr)
            l->ToString();
        if (r != nullptr)
            r->ToString();
    }

    void ToStringInOrder(std::string& someText) {
        std::string retVal = "";
        if (l != nullptr) {
            l->ToStringInOrder(someText);
        }
        someText += std::to_string(data) + " ";
        if (r != nullptr) {
            r->ToStringInOrder(someText);
        }
    }
};

int main() {
    Node* root = new Node(5);
    root->Insert(10);
    root->Insert(20);
    root->Insert(8);
    root->Insert(12);
    root->Insert(17);
    root->Insert(25);
    // root->ToString();
    
    std::string toPrint{};
    root->ToStringInOrder(toPrint);
    std::cout << toPrint << std::endl;

    std::cout << root->Find(18);
    
    // std::cout << (2 << 0);


    root->Clear();
    return 0;
}
