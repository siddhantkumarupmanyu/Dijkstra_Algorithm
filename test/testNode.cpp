#include <limits>
#include <vector>

#include "Edge.hpp"
#include "Node.hpp"
#include "catch_amalgamated.hpp"

void assertEqualEdgeVector(vector<Edge*>& expected, vector<Edge*>& actual) {
    REQUIRE(expected.size() == actual.size());

    for (int i = 0; i < actual.size(); i++) {
        REQUIRE(expected[i]->equals(actual[i]));
    }
}

TEST_CASE("Node constructor") {
    Node* node = new Node("A");
    REQUIRE(node->getName() == "A");

    REQUIRE(node->getNodeCost() == std::numeric_limits<int>::max());
}

TEST_CASE("Node Cost") {
    Node* node = new Node("A");

    node->setNodeCost(4);
    REQUIRE(node->getNodeCost() == 4);
}

TEST_CASE("Add Edge") {
    Node* node = new Node("A");

    node->addEdge(new Edge(10, new Node("B"), node));
    node->addEdge(new Edge(11, new Node("C"), node));

    vector<Edge*> expected;
    expected.push_back(new Edge(10, new Node("B"), node));
    expected.push_back(new Edge(11, new Node("C"), node));

    assertEqualEdgeVector(expected, node->getConnectedEdges());
}

TEST_CASE("source and destination") {
    Node* node = new Node("A");

    REQUIRE(node->isSource() == false);
    REQUIRE(node->isDestination() == false);

    node->setSource(true);
    REQUIRE(node->isSource() == true);

    node->setDestination(true);
    REQUIRE(node->isDestination() == true);
}

TEST_CASE("EdgeWithSortestPathToSource") {
    Node* node = new Node("A");

    REQUIRE(node->getEdgeWithSortestPathToSource() == nullptr);

    Edge* edge = new Edge(20, node, new Node("B"));

    node->setEdgeWithShortestPathToSource(edge);
    REQUIRE(node->getEdgeWithSortestPathToSource()->equals(edge));
}

TEST_CASE("transversed"){
    Node* node = new Node("A");

    REQUIRE(node->isTransversed() == false);

    node->setTransversed(true);

    REQUIRE(node->isTransversed() == true);
}

TEST_CASE("Equals") {
    Node* node1a = new Node("A");
    Node* node1b = new Node("A");
    Node* node2 = new Node("B");

    REQUIRE(node1a->equals(node1b));
    REQUIRE(!node2->equals(node1b));
}