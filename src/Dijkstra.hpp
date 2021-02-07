#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "Edge.hpp"
#include "Node.hpp"

class Dijkstra {
   private:
    Node* sourceNode;
    Node* destinationNode;
    // run()

   public:
    Dijkstra(Node* source, Node* destination);
    ~Dijkstra();
    // getShortestpath()
};

#endif