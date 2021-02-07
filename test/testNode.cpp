#include <limits>

#include "Node.hpp"
#include "catch_amalgamated.hpp"

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

// TEST_CASE("Add Edge"){
//     Node* node = new Node("A");

//     node->addEdge(new Edge());

//     REQUIRE();
// }

TEST_CASE("Equals") {
    Node* node1a = new Node("A");
    Node* node1b = new Node("A");
    Node* node2 = new Node("B");

    REQUIRE(node1a->equals(node1b));
    REQUIRE(!node2->equals(node1b));
}