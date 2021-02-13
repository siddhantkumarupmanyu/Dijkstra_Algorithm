#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>

#include "Edge.hpp"
#include "Node.hpp"

class Dijkstra {
   private:
    Node* sourceNode;
    Node* destinationNode;
    std::vector<Node*> transverseList;
    std::vector<Node*> shortestPathFromDestination;
    void executeAlgorithm();
    void run();
    Node* getSmallestFromTransverseList();
    void addToTransverseList(Node* node);
    void fillShortestPath();

   public:
    Dijkstra(Node* source, Node* destination);
    ~Dijkstra();
    std::vector<Node*> getShortestPathFromDestination();
    std::vector<Node*> getShortestPathToDestination();
};

#endif