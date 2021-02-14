#include "Graph.hpp"

Graph::Graph() {
}

Graph::~Graph() {
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

std::vector<Edge*> Graph::getEdges() {
    return this->edges;
}

Node* Graph::getSourceNode() {
    return this->sourceNode;
}
Node* Graph::getDestinationNode() {
    return this->destinationNode;
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