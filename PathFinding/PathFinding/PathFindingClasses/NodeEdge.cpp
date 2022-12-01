#include "NodeEdge.h"

void Node::PrintPath() {
    Node* current = this;
    std::vector<Node*> nodes{};
    nodes.push_back(current);
    while (current->FromEdge != nullptr) {
        
        current = current->FromEdge->GetOther(current);
        nodes.push_back(current);
    }

    for (int i = nodes.size()-1; i >= 0; --i) {
       std::cout << nodes[i]->Name << " ";
    }
    std::cout << "(" << currentDistance << ")" << std::endl; 
}

Edge* Node::GetEdgeWithNode(Node* node) {
    for (int i = 0; i < Edges.size(); ++i) {
        if (Edges[i]->From == node || Edges[i]->To == node)
            return Edges[i];
    }
}
