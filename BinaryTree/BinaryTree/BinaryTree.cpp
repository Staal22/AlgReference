#include "BinaryTree/Node.h"
// #include "../../Sorting/Sorting/Interfaces/Stringable.h"
#include "../../Sorting/Sorting/SomeScalarClass.h"

int main() {
    SomeScalarClass t = SomeScalarClass();
    NodeT<SomeScalarClass>* templateNode = new NodeT<SomeScalarClass>(SomeScalarClass(15));
    templateNode->Insert(SomeScalarClass(4));
    templateNode->Insert(SomeScalarClass(3));
    templateNode->Insert(SomeScalarClass(4));
    templateNode->Insert(SomeScalarClass(20));
    templateNode->Insert(SomeScalarClass(19));
    templateNode->Insert(SomeScalarClass(16));
    templateNode->Insert(SomeScalarClass(25));
    templateNode->PrintTree();
    templateNode->Delete(SomeScalarClass(20), templateNode);
    std::cout << "---------------------------" << std::endl;
    templateNode->PrintTree();

    
    return 0;
    Node* root = new Node(5);
    root->Insert(10);
    root->Insert(20);
    root->Insert(8);
    root->Insert(12);
    root->Insert(17);
    root->Insert(25);
    root->Insert(1);
    root->Insert(-10);
    root->Insert(4);
    // root->ToString();
    
    std::string toPrint{};
    std::cout << "INORDER" << std::endl;
    root->ToStringInOrder(toPrint);
    std::cout << toPrint << std::endl;

    std::cout << "PREORDER" << std::endl;
    toPrint = "";
    root->ToStringPreOrder(toPrint);
    std::cout << toPrint << std::endl;

    std::cout << "POSTORDER" << std::endl;
    toPrint = "";
    root->ToStringPostOrder(toPrint);
    std::cout << toPrint << std::endl;
    

    std::cout << "PRINT WITH DEPTH" << std::endl;
    root->PrintTree();

    // std::cout << root->Find(18);
    // std::cout << (2 << 0);
    
    root->Clear();
    return 0;
}
