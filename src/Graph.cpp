#include "Graph.hpp"

Graph::Graph() {
}

Graph::~Graph() {
    // this code is untested
    // i don't know how to test this
    deallocateNodes();
    deallocateEdges();
}

void Graph::addNode(Node* node) {
    if (node->isSource()) {
        this->sourceNode = node;
    } else if (node->isDestination()) {
        this->destinationNode = node;
    }
    this->nodes.push_back(node);
}

void Graph::addEdge(Edge* edge) {
    this->edges.push_back(edge);
}

std::vector<Node*> Graph::getNodes() {
    return this->nodes;
}

void Graph::resetNodes() {
    for (auto node : this->nodes) {
        node->reset();
    }
}

void Graph::setSourceAndDestination(Node* source, Node* destination) {
    for (auto node : this->nodes) {
        if (node->equals(source)) {
            this->sourceNode = node;
        } else if (node->equals(destination)) {
            this->destinationNode = node;
        }
    }
    this->resetNodes();
}

std::vector<Edge*> Graph::getEdges() {
    return this->edges;
}

Node* Graph::getSourceNode() {
    return this->sourceNode;
}
Node* Graph::getDestinationNode() {
    return this->destinationNode;
}

Node* Graph::getOrAddNode(Node* node) {
    Node* existingNode = findNode(node);
    if (!existingNode) {
        this->addNode(node);
        existingNode = node;
    }
    return existingNode;
}

Node* Graph::findNode(Node* node) {
    for (auto currentNode : this->nodes) {
        if (currentNode->equals(node)) {
            return currentNode;
        }
    }
    return nullptr;
}

Edge* Graph::getOrAddEdge(Edge* edge) {
    Edge* existingEdge = findEdge(edge);
    if (!existingEdge) {
        this->addEdge(edge);
        existingEdge = edge;
    }
    return existingEdge;
}

Edge* Graph::findEdge(Edge* edge) {
    for (auto currentEdge : this->edges) {
        if (currentEdge->equals(edge)) {
            return currentEdge;
        }
    }
    return nullptr;
}

void Graph::deallocateNodes() {
    for (int i = 0; i < this->nodes.size(); i++) {
        delete this->nodes[i];
    }
    this->nodes.clear();
}

void Graph::deallocateEdges() {
    for (int i = 0; i < this->edges.size(); i++) {
        delete this->edges[i];
    }
    this->edges.clear();
}