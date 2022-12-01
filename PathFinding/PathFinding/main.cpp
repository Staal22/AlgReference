
#include <iostream>
#include <queue>
#include <algorithm>

#include <functional>
#include "PathFindingClasses/NodeEdge.h"
#include "PathFindingClasses/PathFinder.h"
#include "PriorityQueueDerived.h"

int main() {

	
	/*
	// PriorityQueueDerived<Path*, std::vector<Path*>, std::greater<Path*>> priQueue{};
	auto comapre = [](Path* a, Path* b){return a->CalculateLength() < b->CalculateLength();};
	// std::priority_queue<Path*, std::vector<Path*>, decltype(comapre)> priQueue(comapre);
	PriorityQueueDerived<Path*, std::vector<Path*>, decltype(comapre)> priQueue(comapre);
	Path* p1 = new Path();
	p1->Edges.push_back(Edge(2));
	p1->Edges.push_back(Edge(4));
	p1->Edges.push_back(Edge(2));
	
	Path* p2 = new Path();
	p2->Edges.push_back(Edge(4));
	p2->Edges.push_back(Edge(4));
	p2->Edges.push_back(Edge(1));
	
	Path* p3 = new Path();
	p3->Edges.push_back(Edge(14));
	p3->Edges.push_back(Edge(4));
	p3->Edges.push_back(Edge(1));
	
	priQueue.push(p2);
	priQueue.push(p1);
	priQueue.push(p3);
	*/

    
    PathFinder pathFind{};
    pathFind.AddNode(new Node('A', 23.91));
    pathFind.AddNode(new Node('B', 25.98));
    pathFind.AddNode(new Node('C', 16.26));
    pathFind.AddNode(new Node('D', 13.96));
    pathFind.AddNode(new Node('E', 16.11));
    pathFind.AddNode(new Node('F', 9.14));
    pathFind.AddNode(new Node('G', 8.29));
    pathFind.AddNode(new Node('H', 0));

	pathFind.AddEdge('A', 'E', 8.09);
	pathFind.AddEdge('A', 'B', 5.67);
	
	pathFind.AddEdge('B', 'C', 10.00);
	pathFind.AddEdge('B', 'D', 15.37);
	
	pathFind.AddEdge('C', 'E', 6.5);
	pathFind.AddEdge('C', 'G', 8.62);
	pathFind.AddEdge('C', 'F', 9.92);
	
	pathFind.AddEdge('D', 'G', 6.1);
	
	pathFind.AddEdge('E', 'F', 7.1);
	
	pathFind.AddEdge('F', 'H', 9.1);

	pathFind.AddEdge('G', 'H', 8.35);
    std::cout << "EDGES : " << std::endl;
    for (int i = 0; i < pathFind.Edges.size(); ++i) {
        std::cout << pathFind.Edges[i]->From->Name << " <-> " << pathFind.Edges[i]->To->Name << std::endl;
    }

    // print all nodes and their edges
    std::cout << std::endl;
    std::cout << "NODES WITH OWNING EDGES : " << std::endl;
    for (int i = 0; i < pathFind.Nodes.size(); ++i) {
        Node* node = pathFind.Nodes[i];

        std::cout << node->Name << " -> : ";
        for (int j = 0; j < node->Edges.size(); ++j) 
            std::cout << node->Edges[j]->GetOther(node)->Name << " ";
        std::cout << std::endl;
    }
	pathFind.Astar2('A', 'H');
	
	pathFind.Dijkstra2('A', 'H');
    return 0;
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

    pathFinder.Dijkstra('A', 'D');

    
    return 0;
}
