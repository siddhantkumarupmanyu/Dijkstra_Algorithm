#include "Edge.hpp"
#include "Node.hpp"
#include "catch_amalgamated.hpp"

using namespace std;

TEST_CASE("Edge Constructor", "[Edge]") {
    shared_ptr<Node> firstNode = make_shared<Node>("A");
    shared_ptr<Node> secondNode = make_shared<Node>("B");
    
    shared_ptr<Edge> edge = make_shared<Edge>(10, firstNode, secondNode);
    REQUIRE(edge->getCost() == 10);                     // edge should have a cost

    //edge should have two nodes
    REQUIRE(edge->getFirstNode().lock() == firstNode);  // first node in edge
    REQUIRE(edge->getSecondNode().lock() == secondNode);  // second node in edge

    //edge should return other node
    REQUIRE(edge->getOtherNode(firstNode).lock() == secondNode); // other node should be secondNode
    REQUIRE(edge->getOtherNode(secondNode).lock() == firstNode); // other node should be firstNode
}