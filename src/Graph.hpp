#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

#include "Node.hpp"

class Graph {
   private:
    std::vector<Node*> nodes;

   public:
    Graph();
    ~Graph();
    void addNode(Node* node);
    std::vector<Node*> getNodes();
};

#endif