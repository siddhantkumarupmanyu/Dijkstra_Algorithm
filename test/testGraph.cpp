#include <vector>

#include "Graph.hpp"
#include "Node.hpp"
#include "catch_amalgamated.hpp"

using namespace std;

static void assertEqualNodeVector(vector<Node*>& expected, vector<Node*>& actual) {
    REQUIRE(expected.size() == actual.size());

    for (int i = 0; i < actual.size(); i++) {
        REQUIRE(expected[i]->equals(actual[i]));
    }
}

TEST_CASE("add node") {
    Graph* graph = new Graph();

    auto nodeA = new Node("A");
    auto nodeB = new Node("B");
    auto nodeC = new Node("C");

    vector<Node*> expected;
    expected.push_back(nodeA);
    expected.push_back(nodeB);
    expected.push_back(nodeC);

    graph->addNode(nodeA);
    graph->addNode(nodeB);
    graph->addNode(nodeC);

    vector<Node*> actual = graph->getNodes();

    assertEqualNodeVector(expected, actual);
}

//     graph->addEdge();
//     graph->getSourceNode();
//     graph->getDestinationNode();
