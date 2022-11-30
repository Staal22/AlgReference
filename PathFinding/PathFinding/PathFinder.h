#pragma once

#include "NodeEdge.h"
class PathFinder {
public:
    std::vector<Node*> Nodes{};
    std::vector<Edge*> Edges{};
    
    void AddNode(Node* node);
    void AddEdge(char n1, char n2, float distance);

    // void PrintTerminal2D();
    void Dijkstra(Node* start, Node* end);
    void Astar();

    Node* FindNode(char c);
};

