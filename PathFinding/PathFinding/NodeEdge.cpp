#include "NodeEdge.h"

Edge* Node::GetEdgeWithNode(Node* node) {
    for (int i = 0; i < Edges.size(); ++i) {
        if (Edges[i]->From == node || Edges[i]->To == node)
            return Edges[i];
    }
}
