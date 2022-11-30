#include "PathFinder.h"

#include <iostream>
#include <queue>

void PathFinder::AddNode(Node* node) {
	Nodes.push_back(node);
}

void PathFinder::AddEdge(char n1, char n2, float distance) {
	Node* nn1 = nullptr;
	Node* nn2 = nullptr;
	
	nn1 = FindNode(n1);
	nn2 = FindNode(n2);

	if (nn1 == nullptr || nn2 == nullptr) {
		std::cout << "ERROR: ADDED EDGE DID NOT FIND TWO CORRECPONDING NODES" << std::endl;
		throw std::invalid_argument("ERROR: ADDED EDGE DID NOT FIND TWO CORRECPONDING NODES");
	}
	
	Edge* edge = new Edge(nn1,nn2, distance);
	nn1->Edges.push_back(edge);
	nn2->Edges.push_back(edge);
	
	Edges.push_back(edge);
}

void PathFinder::Dijkstra(Node* start, Node* end) {
	// SETUP
	// ------------------------------------------------------
	
	// priority queue
	std::priority_queue<Path*, std::vector<Path*>, std::greater<Path*>> priQueue{};
	
	std::vector<Node*> visitedNodes{};

	visitedNodes.push_back(start);
	
	// making path from all edges at the start node
	for (int i = 0; i < start->Edges.size(); ++i) {
		Path* tempPath =  new Path();
		Edge edge(start, Edges[i]->GetOther(start), Edges[i]->Distance);
		tempPath->Edges.push_back(edge);

		// sets the path that we came from for each node
		Node* other =  start->Edges[i]->GetOther(start) ;
		other->FromEdge = Edges[i];
		
		priQueue.push(tempPath);
	}

	Path* shortestPath{};

	// ACTUAL PATHFINDING
	// ------------------------------------------------------
	while (!priQueue.empty()) {
		Path* tempPath = priQueue.top();
		priQueue.pop(); // removes this path temporarily
		
		Node* lastNode = tempPath->GetEndNode();
		visitedNodes.push_back(lastNode);

		if (lastNode == end) {
			shortestPath = tempPath;
			break;
		}
		
		// for each edge of last node, create new path
		for (int i = 0; i < lastNode->Edges.size(); ++i) {
			if (lastNode->Edges[i] == lastNode->GetFromEdge()) 
				continue;
			if (lastNode->Edges[i]->GetOther(lastNode)->BVisited) 
				continue;

			
			Path* newPath = new Path(*tempPath); // copeis
			Node* other = lastNode->Edges[i]->GetOther(lastNode);

			other->FromEdge = other->GetEdgeWithNode(lastNode);
			
			Edge newEdge(lastNode, other, Edges[i]->Distance); // constructs new edge
			newPath->Edges.push_back(newEdge);
			priQueue.push(newPath);
		}

		// TODO remove this very unproffesional message vv
		// stay memory safe kids
		delete tempPath;
	}

	std::cout << "SHORTEST PATH : " << std::endl;
	shortestPath->PrintPath();
	
}

Node* PathFinder::FindNode(char c) {
	for (int i = 0; i < Nodes.size(); ++i) {
		if (Nodes[i]->Name == c) {
			return Nodes[i];
		}
	}
	return nullptr;
}
