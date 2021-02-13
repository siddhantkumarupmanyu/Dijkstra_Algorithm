#include "Dijkstra.hpp"

#include <algorithm>

using namespace std;

Dijkstra::Dijkstra(Node* source, Node* destination) {
    this->sourceNode = source;
    this->destinationNode = destination;
    this->sourceNode->setSource(true);
    this->destinationNode->setDestination(true);
}

Dijkstra::~Dijkstra() {
}

vector<Node*> Dijkstra::getShortestPathFromDestination() {
    this->sourceNode->setNodeCost(0);
    run();
    fillShortestPath();
    return this->shortestPathFromDestination;
}

vector<Node*> Dijkstra::getShortestPathToDestination() {
    // TODO: complete this
    
    vector<Node*> shortestPathToDestination(this->shortestPathFromDestination);
    reverse(shortestPathToDestination.begin(), shortestPathToDestination.end());
    return shortestPathToDestination;
}

void Dijkstra::run() {
    Node* currentNode = this->sourceNode;
    bool reached = false;

    while (true) {
        auto edges = currentNode->getConnectedEdges();

        for (int i = 0; i < edges.size(); i++) {
            Edge* currentEdge = edges[i];

            Node* otherNode = currentEdge->getOtherNode(currentNode);

            int otherNodeNewCost = currentNode->getNodeCost() + currentEdge->getCost();

            if (otherNode->isDestination() && (otherNode->getNodeCost() > otherNodeNewCost)) {
                otherNode->setNodeCost(otherNodeNewCost);
                otherNode->setEdgeWithShortestPathToSource(currentEdge);
                reached = true;
            }

            else if (otherNode->getNodeCost() > otherNodeNewCost) {
                if (reached && (otherNodeNewCost >= (this->destinationNode->getNodeCost()))) {
                    continue;
                }

                otherNode->setNodeCost(otherNodeNewCost);

                otherNode->setTransversed(false);

                otherNode->setEdgeWithShortestPathToSource(currentEdge);

                addToTransverseList(otherNode);
            }
        }

        if (this->transverseList.size() == 0) {
            break;
        }

        currentNode = getSmallestFromTransverseList();
    }
}

Node* Dijkstra::getSmallestFromTransverseList() {
    Node* smallest = this->transverseList[0];
    int index = 0;
    for (int i = 0; i < this->transverseList.size(); i++) {
        auto currentNode = this->transverseList[i];
        if (currentNode->getNodeCost() < smallest->getNodeCost()) {
            smallest = currentNode;
            index = i;
        }
    }

    std::vector<Node*>::iterator it = this->transverseList.begin();
    std::advance(it, index);
    this->transverseList.erase(it);

    return smallest;
}

void Dijkstra::fillShortestPath() {
    Node* currentNode = destinationNode;
    while (!currentNode->isSource()) {
        shortestPathFromDestination.push_back(currentNode);
        auto edge = currentNode->getEdgeWithSortestPathToSource();
        currentNode = edge->getOtherNode(currentNode);
    }

    shortestPathFromDestination.push_back(this->sourceNode);
}

void Dijkstra::addToTransverseList(Node* node) {
    this->transverseList.push_back(node);
}