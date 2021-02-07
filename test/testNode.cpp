#include <bits/stdc++.h>

#include "Edge.hpp"
#include "Node.hpp"
#include "catch_amalgamated.hpp"

using namespace std;

TEST_CASE("Node Constructor", "[Node]") {
    shared_ptr<Node> node = make_shared<Node>("A");
    REQUIRE(node->getName() == "A");
    REQUIRE(node->getCost() == INT_MAX);

    node->setCost(2);
    REQUIRE(node->getCost() == 2);
}

TEST_CASE("adding Node To One Adds It To Other") {
    shared_ptr<Node> nodeA = make_shared<Node>("A");
    shared_ptr<Node> nodeB = make_shared<Node>("B");

    nodeA->addNode(nodeB, 10);
    auto nodes = nodeA->getConnectedNodes();

    REQUIRE(nodes[0].equals(nodeB))
}

// TEST_CASE("nodes having connecting edge"){

// }

TEST_CASE("Node equal") {
    shared_ptr<Node> node1a = make_shared<Node>("A");
    shared_ptr<Node> node1b = make_shared<Node>("A");
    shared_ptr<Node> node2 = make_shared<Node>("B");

    REQUIRE(node1a->equals(node1b));
    REQUIRE(!node2->equals(node1b));
}
