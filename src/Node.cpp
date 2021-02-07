#include "Node.hpp"

Node::Node(string name) {
    this->name = name;
}

Node::~Node() {
}

void Node::setCost(int value) {
    this->cost = value;
}

int Node::getCost() {
    return this->cost;
}

string Node::getName() {
    return this->name;
}
