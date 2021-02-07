#include "Edge.hpp"

Edge::Edge(int cost) {
    this->cost = cost;
}

Edge::~Edge() {
}

int Edge::getCost() {
    return this->cost;
}

std::weak_ptr<Node> Edge::getFirstNode(){
    return this->firstNode;
}