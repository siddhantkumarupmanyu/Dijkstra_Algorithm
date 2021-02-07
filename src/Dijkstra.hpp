#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>

#include "Edge.hpp"
#include "Node.hpp"

using namespace std;

class Dijkstra {
   private:
    Node* sourceNode;
    Node* destinationNode;
    vector<Node*> transverseList;
    vector<Node*> shortestPath;
    void run();
    Node* getSmallestFromTransverseList();
    void addToTransverseList(Node* node);
    void fillShortestPath();

   public:
    Dijkstra(Node* source, Node* destination);
    ~Dijkstra();
    vector<Node*> getShortestPath();
};

#endif