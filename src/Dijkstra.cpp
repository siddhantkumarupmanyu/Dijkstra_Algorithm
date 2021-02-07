#include "Dijkstra.hpp"

Dijkstra::Dijkstra(Node* source, Node* destination) {
    this->sourceNode = source;
    this->destinationNode = destination;
    this->sourceNode->setSource(true);
    this->destinationNode->setDestination(true);
}

Dijkstra::~Dijkstra() {
}