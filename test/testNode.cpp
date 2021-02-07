#include "catch_amalgamated.hpp"
#include <memory>
#include "Node.hpp"

TEST_CASE( "Node Constructor", "[Node]" ) {
    std::shared_ptr<Node> node = std::make_shared<Node>("A");
    REQUIRE(node->getName() == "A");
    node->setCost(2);
    REQUIRE(node->getCost() == 2);
}
