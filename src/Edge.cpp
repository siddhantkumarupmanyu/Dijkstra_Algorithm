#include "Edge.hpp"

#include "Node.hpp"

Edge::Edge(int cost, Node* firstNode, Node* secondNode) {
    this->cost = cost;
    this->firstNode = firstNode;
    this->secondNode = secondNode;
}

Edge::~Edge() {
}

int Edge::getCost() {
    return this->cost;
}

Node* Edge::getFirstNode() {
    return this->firstNode;
}

Node* Edge::getSecondNode() {
    return this->secondNode;
}

Node* Edge::getOtherNode(Node* currentNode) {
    if (this->firstNode->equals(currentNode)) {
        return this->secondNode;
    } else if (this->secondNode->equals(currentNode)) {
        return this->firstNode;
    } else {
        // todo throw exception
    }
}

bool Edge::contains(Node* node){
    return this->firstNode->equals(node) || this->secondNode->equals(node);    
}

bool Edge::equals(Edge* other) {
    bool firstNodeMatched = this->firstNode->equals(other->firstNode) || this->firstNode->equals(other->secondNode);
    bool secondNodeMatched = this->secondNode->equals(other->firstNode) || this->secondNode->equals(other->secondNode);
    if (firstNodeMatched && secondNodeMatched) {
        // todo fails fast if this cost not equals to other
        return true;
    }
    return false;
}