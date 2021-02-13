#include "Edge.hpp"
#include "Node.hpp"
#include "catch_amalgamated.hpp"

TEST_CASE("Edge Constructor") {
    Node* nodeA = new Node("A");
    Node* nodeB = new Node("B");

    Edge* edge = new Edge(10, nodeA, nodeB);

    REQUIRE(edge->getCost() == 10);
    REQUIRE(edge->getFirstNode()->equals(nodeA));
    REQUIRE(edge->getSecondNode()->equals(nodeB));
}

TEST_CASE("Other Node") {
    Node* nodeA = new Node("A");
    Node* nodeB = new Node("B");

    Edge* edge = new Edge(10, nodeA, nodeB);

    REQUIRE(edge->getOtherNode(nodeA)->equals(nodeB));
    REQUIRE(edge->getOtherNode(nodeB)->equals(nodeA));
}

TEST_CASE("Contains"){
    Node* nodeA = new Node("A");
    Node* nodeB = new Node("B");
    Node* nodeC = new Node("C");

    Edge* edge = new Edge(10, nodeA, nodeB);

    REQUIRE(edge->contains(nodeA) == true);
    REQUIRE(edge->contains(nodeB) == true);
    REQUIRE(edge->contains(nodeC) == false);

}

TEST_CASE("equals"){
    Node* nodeA = new Node("A");
    Node* nodeB = new Node("B");
    Node* nodeC = new Node("C");

    Edge* edge1a = new Edge(10, nodeA, nodeB);
    Edge* edge1b = new Edge(10, nodeA, nodeB);
    Edge* edge1c = new Edge(10, nodeB, nodeA);
    Edge* edge2 = new Edge(10, nodeA, nodeC);

    REQUIRE(edge1a->equals(edge1b));
    REQUIRE(edge1c->equals(edge1b));

    REQUIRE(!edge2->equals(edge1b));

}