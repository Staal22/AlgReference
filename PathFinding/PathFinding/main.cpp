
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>

#include "PathFinder.h"
#include "PriorityQueueDerived.h"

int main() {

	
	// PriorityQueueDerived<Path*, std::vector<Path*>, std::greater<Path*>> priQueue{};
	std::priority_queue<Path*, std::vector<Path*>, std::greater<Path*>> priQueue{};
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
 
	int size = priQueue.size();
	for (int i = 0; i < size; ++i) {
		std::cout << priQueue.top()->CalculateLength() << std::endl;
		priQueue.pop();
	}
	
    return 0;
    
    PathFinder pathFind{};
    pathFind.AddNode(new Node('A'));
    pathFind.AddNode(new Node('B'));
    pathFind.AddNode(new Node('C'));
    pathFind.AddNode(new Node('D'));
    pathFind.AddNode(new Node('E'));
    pathFind.AddNode(new Node('F'));
    
    pathFind.AddEdge('A', 'B', 10);
    pathFind.AddEdge('A', 'C', 15);
    pathFind.AddEdge('B', 'F', 15);
    pathFind.AddEdge('B', 'D', 12);
    pathFind.AddEdge('C', 'E', 10);
    pathFind.AddEdge('D', 'F', 1);
    pathFind.AddEdge('D', 'E', 2);
    pathFind.AddEdge('F', 'F', 5);

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
	pathFind.Astar('A', 'E');
	
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
