#include "Edge.hpp"
#include "Node.hpp"
#include "catch_amalgamated.hpp"

using namespace std;

TEST_CASE("Edge Constructor", "[Edge]") {
    shared_ptr<Node> firstNode = make_shared<Node>("A");
    shared_ptr<Node> secondNode = make_shared<Node>("B");
    shared_ptr<Edge> edge = make_shared<Edge>(10);
    REQUIRE(edge->getCost() == 10);  // edge should have a cost
    REQUIRE(edge->getFirstNode() == firstNode) // first node in edge
}