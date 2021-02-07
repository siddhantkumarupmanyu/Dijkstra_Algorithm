#include "catch_amalgamated.hpp"
#include "Edge.hpp"
#include "Node.hpp"

using namespace std;

TEST_CASE( "Node Constructor", "[Node]" ) {
    shared_ptr<Node> node = make_shared<Node>("A");
    REQUIRE(node->getName() == "A");
    node->setCost(2);
    REQUIRE(node->getCost() == 2);
}

// TEST_CASE("multiple Edges In Node", "[Node Edges]"){
//     shared_ptr<Node> node = make_shared<Node>("A");

//     // node->add.Edge(make_shared<Edge>(10, node));
// }

// TEST_CASE("nodes having connecting edge"){
    
// }

TEST_CASE("Node equal"){
    shared_ptr<Node> node1a = make_shared<Node>("A");
    shared_ptr<Node> node1b = make_shared<Node>("A");
    shared_ptr<Node> node2 = make_shared<Node>("B");

    REQUIRE(node1a == node1b);
    REQUIRE(node2 != node1b);
}


