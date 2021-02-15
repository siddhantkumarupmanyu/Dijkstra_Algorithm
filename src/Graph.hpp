#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

#include "Edge.hpp"
#include "Node.hpp"

class Graph {
   private:
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;
    Node* sourceNode;
    Node* destinationNode;
    Node* findNode(Node* node);
    Edge* findEdge(Edge* edge);
    void deallocateNodes();
    void deallocateEdges();

   public:
    Graph();
    ~Graph();
    void addNode(Node* node);
    void addEdge(Edge* edge);
    std::vector<Node*> getNodes();
    std::vector<Edge*> getEdges();
    Node* getSourceNode();
    Node* getDestinationNode();
    Node* getOrAddNode(Node* node);
    Edge* getOrAddEdge(Edge* edge);
    void resetNodes();
};

#endif