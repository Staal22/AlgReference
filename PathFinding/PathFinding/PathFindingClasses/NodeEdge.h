#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>

// forward declerations
class Edge;

// classes
class Node {
public:
    Node(char name) {
        Name = name;
    }

    Node(char name, float heuristic) : Node(name) {
        Heuristic = heuristic;
    }
    
    bool BVisited{false};
    char Name;
    float Heuristic{};
    std::vector<Edge*> Edges{};
    Edge* FromEdge{};
    float currentDistance{99999999.f};

    float GetHueristic() {
        return Heuristic;
    }

    // assumes theat the index 
    Edge* GetFromEdge() {
        if (FromEdge == nullptr) {
            throw std::invalid_argument("ERROR EDGE DOES NOT HAVE A FROM NODE");
        }
        return FromEdge;
    }

    void PrintPath();


    Edge* GetEdgeWithNode(Node* node);


};

class Edge {
public:
    Edge() = default;
    Edge(float distance) { // TODO remove!
        Distance = distance;
    }
    Edge(Node* from, Node* to, float distance) {
        From = from;
        To = to;
        Distance = distance;
    }
    
    Node* GetOther(Node* current) {
        if (From == current) {
            return To;
        }
        return From;
    }
    
    Node* To{};
    Node* From{};
    float Distance{};
    
};

class Path {
public:
    std::vector<Edge> Edges{};


    float CalculateLength() const {
        float length{};
        for (int i = 0; i < Edges.size(); ++i) {
            length += Edges[i].Distance;
        }
        return length;
    }

    float CalculateLengthHueristic() {
        return CalculateLength() + GetEndNode()->GetHueristic();
    }

    Node* GetEndNode() {
        return Edges[Edges.size() -1].To;
    }

    void PrintPath() {
        for (int i = 0; i < Edges.size(); ++i) {
            std::cout << Edges[i].From->Name << " -> " << Edges[i].To->Name << " ";
        }
        std::cout << "(" << CalculateLength() << ")";
        std::cout << std::endl;
    }
    
	operator float() const { return CalculateLength(); } // to float
	// bool operator < ( const Path* r) const { return CalculateLength() < r->CalculateLength(); } 
    

    // friend bool operator<(Path* l, Path* r);
};

// bool operator<(Path*l, Path* r) {
        // return  l->CalculateLength() < r->CalculateLength();
    // }
