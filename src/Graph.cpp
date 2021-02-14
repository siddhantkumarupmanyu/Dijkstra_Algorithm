#include "Graph.hpp"

Graph::Graph(/* args */) {
}

Graph::~Graph() {
}

void Graph::addNode(Node* node) {
    this->nodes.push_back(node);
}
std::vector<Node*> Graph::getNodes() {
    return this->nodes;
}