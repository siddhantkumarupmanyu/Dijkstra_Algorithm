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
};

#endif