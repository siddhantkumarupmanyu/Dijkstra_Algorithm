#include "Node.hpp"

#include <limits>

Node::Node(string name) {
    this->name = name;
    this->nodeCost = std::numeric_limits<int>::max();
}

Node::~Node() {
}

string Node::getName() {
    return this->name;
}

int Node::getNodeCost() {
    return this->nodeCost;
}

void Node::setNodeCost(int value) {
    nodeCost = value;
}

void Node::addEdge(Edge* edge) {
}

vector<Edge*>& getConnectedEdges() {
}

bool Node::equals(Node* other) {
    return other->name == this->name;
}