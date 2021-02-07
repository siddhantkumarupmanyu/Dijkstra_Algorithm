#include "Node.hpp"

Node::Node(string name) {
    this->name = name;
}

Node::~Node() {
}

void Node::setCost(int value) {
}

int Node::getCost() {
}

string Node::getName() {
    return this->name;
}
