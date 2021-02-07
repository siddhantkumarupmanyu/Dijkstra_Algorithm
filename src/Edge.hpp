#ifndef EDGE_HPP
#define EDGE_HPP

#include <memory>

#include "Node.hpp"

class Edge {
   private:
    int cost;
    std::weak_ptr<Node> firstNode;
    std::weak_ptr<Node> secondNode;

   public:
    Edge(int cost, std::weak_ptr<Node> firstNode, std::weak_ptr<Node> secondNode);
    ~Edge();
    int getCost();
    std::weak_ptr<Node> getFirstNode();
    std::weak_ptr<Node> getSecondNode();
    std::weak_ptr<Node> getOtherNode(const std::shared_ptr<Node> node);
};

#endif