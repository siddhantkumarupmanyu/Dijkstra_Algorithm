#include <vector>

#include "Edge.hpp"
#include "Graph.hpp"
#include "Node.hpp"
#include "Utils.hpp"
#include "catch_amalgamated.hpp"

using namespace std;

TEST_CASE("Nodes") {
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

TEST_CASE("Edges") {
    Graph* graph = new Graph();

    auto nodeA = new Node("A");
    auto nodeB = new Node("B");
    auto nodeC = new Node("C");

    auto A_B = new Edge(10, nodeA, nodeB);
    auto B_C = new Edge(16, nodeB, nodeC);
    auto C_A = new Edge(4, nodeC, nodeA);

    vector<Edge*> expected;
    expected.push_back(A_B);
    expected.push_back(B_C);
    expected.push_back(C_A);

    graph->addEdge(A_B);
    graph->addEdge(B_C);
    graph->addEdge(C_A);

    vector<Edge*> actual = graph->getEdges();

    assertEqualEdgeVector(expected, actual);
}

TEST_CASE("Source Node And Destination Node") {
    Graph* graph = new Graph();

    auto nodeA = new Node("A");
    auto nodeB = new Node("B");
    auto nodeC = new Node("C");

    vector<Node*> expected;
    expected.push_back(nodeA);
    expected.push_back(nodeB);
    expected.push_back(nodeC);

    nodeA->setSource(true);
    nodeC->setDestination(true);

    graph->addNode(nodeA);
    graph->addNode(nodeB);
    graph->addNode(nodeC);

    REQUIRE(nodeA->equals(graph->getSourceNode()));
    REQUIRE(nodeC->equals(graph->getDestinationNode()));
}

TEST_CASE("getOrAddNode") {
    Graph* graph = new Graph();

    auto nodeA = new Node("A");
    auto nodeB = new Node("B");
    auto nodeC = new Node("C");

    vector<Node*> expected;
    expected.push_back(nodeA);
    expected.push_back(nodeB);
    expected.push_back(nodeC);

    graph->getOrAddNode(nodeA);
    graph->getOrAddNode(nodeB);
    graph->getOrAddNode(nodeC);

    auto nodeBDuplicate = new Node("B");

    REQUIRE(nodeB == graph->getOrAddNode(nodeBDuplicate));
}

TEST_CASE("getOrAddEdge") {
    Graph* graph = new Graph();

    auto nodeA = new Node("A");
    auto nodeB = new Node("B");
    auto nodeC = new Node("C");

    auto A_B = new Edge(10, nodeA, nodeB);
    auto B_C = new Edge(16, nodeB, nodeC);
    auto C_A = new Edge(4, nodeC, nodeA);

    vector<Edge*> expected;
    expected.push_back(A_B);
    expected.push_back(B_C);
    expected.push_back(C_A);

    graph->getOrAddEdge(A_B);
    graph->getOrAddEdge(B_C);
    graph->getOrAddEdge(C_A);

    auto C_ADuplicate = new Edge(4, nodeC, nodeA);

    REQUIRE(C_A == graph->getOrAddEdge(C_ADuplicate));
}