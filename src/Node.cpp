#include "Node.hpp"
#include <bits/stdc++.h>

Node::Node(string name) {
    this->name = name;
    this->cost = INT_MAX;
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

// void Node::addNode(weak_ptr<Node> node, int cost) {
//     this->nodes.insert(pair<weak_ptr<Node>, int>(node, cost));
// }

bool Node::equals(const shared_ptr<Node> other) {
    if (this->name == other->name) {
        return true;
    } else {
        return false;
    }
}
