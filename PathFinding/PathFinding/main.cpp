
#include <iostream>

#include "PathFinder.h"

int maisn() {
    PathFinder pathFinder{};
    pathFinder.AddNode(new Node('A'));
    pathFinder.AddNode(new Node('B'));
    pathFinder.AddNode(new Node('C'));
    pathFinder.AddNode(new Node('D'));
    pathFinder.AddNode(new Node('E'));
    pathFinder.AddEdge('A', 'B', 1.f);
	pathFinder.AddEdge('A', 'C', 2.f);
	pathFinder.AddEdge('B', 'C', 2.f);
	pathFinder.AddEdge('C', 'D', 3.f);
	pathFinder.AddEdge('D', 'E', 1.f);
	pathFinder.AddEdge('A', 'E', 5.f);
	pathFinder.AddEdge('C', 'E', 4.f);

    std::cout << "EDGES : " << std::endl;
    for (int i = 0; i < pathFinder.Edges.size(); ++i) {
        std::cout << pathFinder.Edges[i]->From->Name << " <-> " << pathFinder.Edges[i]->To->Name << std::endl;
    }

    // print all nodes and their edges
    std::cout << std::endl;
    std::cout << "NODES WITH OWNING EDGES : " << std::endl;
    for (int i = 0; i < pathFinder.Nodes.size(); ++i) {
        Node* node = pathFinder.Nodes[i];

        std::cout << node->Name << " -> : ";
        for (int j = 0; j < node->Edges.size(); ++j) 
            std::cout << node->Edges[j]->GetOther(node)->Name << " ";
        std::cout << std::endl;
    }

    pathFinder.Dijkstra(pathFinder.FindNode('A'), pathFinder.FindNode('D'));

    
    return 0;
}
