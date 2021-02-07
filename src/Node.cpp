#include "Node.hpp"

#include <limits>

Node::Node(string name) {
    this->name = name;
    this->nodeCost = std::numeric_limits<int>::max();
    this->source = false;
    this->destination = false;
    this->edgeWithShortestPathToSource = nullptr;
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

bool Node::isSource() {
    return this->source;
}

void Node::setSource(bool value) {
    this->source = value;
}

bool Node::isDestination() {
    return this->destination;
}

void Node::setDestination(bool value) {
    this->destination = value;
}

void Node::addEdge(Edge* edge) {
    this->edges.push_back(edge);
}

vector<Edge*>& Node::getConnectedEdges() {
    return this->edges;
}

void Node::setEdgeWithShortestPathToSource(Edge* edge) {
    this->edgeWithShortestPathToSource = edge;
}
Edge* Node::getEdgeWithSortestPathToSource() {
    return this->edgeWithShortestPathToSource;
}

bool Node::equals(Node* other) {
    return other->name == this->name;
}