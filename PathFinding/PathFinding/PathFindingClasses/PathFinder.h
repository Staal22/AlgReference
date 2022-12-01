#pragma once

#include "NodeEdge.h"
class PathFinder {
public:
    std::vector<Node*> Nodes{};
    std::vector<Edge*> Edges{};
    
    void AddNode(Node* node);
    void AddEdge(char n1, char n2, float distance);

    // void PrintTerminal2D();
    void Dijkstra(char startChar, char endChar);
    void Astar(char startChar, char endChar);

    Node* FindNode(char c);
};

