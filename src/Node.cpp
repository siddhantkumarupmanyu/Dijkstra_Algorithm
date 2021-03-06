#include "Node.hpp"

#include <limits>

#include "Edge.hpp"

using namespace std;

Node::Node(string name) {
    this->name = name;
    this->nodeCost = std::numeric_limits<int>::max();
    this->source = false;
    this->destination = false;
    this->edgeWithShortestPathToSource = nullptr;
    this->transversed = false;
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

bool Node::isTransversed() {
    return this->transversed;
}
void Node::setTransversed(bool value) {
    this->transversed = value;
}

void Node::reset() {
    this->nodeCost = std::numeric_limits<int>::max();
}

void Node::addEdge(Edge* edge) {
    //TODO: fail fast if one of the node in edge is not this Node

    if (!contains(edge)) {
        this->edges.push_back(edge);
    }
}

bool Node::contains(Edge* edgeToFind) {
    for (auto edge : this->edges) {
        if (edge->equals(edgeToFind)) {
            return true;
        }
    }
    return false;
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