#ifndef EDGE_HPP
#define EDGE_HPP

#include <memory>
#include "Node.hpp"

class Edge
{
private:
    int cost;
    std::weak_ptr<Node> firstNode;
    std::weak_ptr<Node> secondNode;
public:
    Edge(int cost);
    ~Edge();
    int getCost();
    std::weak_ptr<Node> getFirstNode();
};

#endif