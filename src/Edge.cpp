#include "Edge.hpp"

Edge::Edge(int cost, std::weak_ptr<Node> firstNode, std::weak_ptr<Node> secondNode) {
    this->cost = cost;
    this->firstNode = firstNode;
    this->secondNode = secondNode;
}

Edge::~Edge() {
}

int Edge::getCost() {
    return this->cost;
}

std::weak_ptr<Node> Edge::getFirstNode() {
    return this->firstNode;
}

std::weak_ptr<Node> Edge::getSecondNode() {
    return this->secondNode;
}

std::weak_ptr<Node> Edge::getOtherNode(const std::shared_ptr<Node> node) {
    if (node == firstNode.lock()) {
        return secondNode;
    } else if (node == secondNode.lock()) {
        return firstNode;
    } else {
        // todo: throw exception
    }
}