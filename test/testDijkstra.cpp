#include <iostream>

#include "Dijkstra.hpp"
#include "Edge.hpp"
#include "Node.hpp"
#include "catch_amalgamated.hpp"

using namespace std;

// TEST_CASE("Dijkstra Constrcutor"){
//     Node*
// }

Node* source;
Node* destination;

void setUpNodes();

void assertEqualNodeVector(vector<Node*>& expected, vector<Node*>& actual);

TEST_CASE("Dijkstra algorithm") {
    setUpNodes();

    Dijkstra* runner = new Dijkstra(source, destination);

    vector<Node*> expected;

    expected.push_back(new Node("J"));
    expected.push_back(new Node("G"));
    expected.push_back(new Node("H"));
    expected.push_back(new Node("C"));
    expected.push_back(new Node("A"));

    vector<Node*> actual = runner->getShortestPath();  // should return copy of vector containing shortest path

    assertEqualNodeVector(expected, actual);
}

void assertEqualNodeVector(vector<Node*>& expected, vector<Node*>& actual) {
    REQUIRE(expected.size() == actual.size());

    for (int i = 0; i < actual.size(); i++) {
        REQUIRE(expected[i]->equals(actual[i]));
    }
}

void setUpNodes() {
    auto nodeA = new Node("A");
    auto nodeB = new Node("B");
    auto nodeC = new Node("C");
    auto nodeD = new Node("D");
    auto nodeE = new Node("E");
    auto nodeF = new Node("F");
    auto nodeG = new Node("G");
    auto nodeH = new Node("H");
    auto nodeI = new Node("I");
    auto nodeJ = new Node("J");
    auto nodeK = new Node("K");

    auto A_B = new Edge(1, nodeA, nodeB);
    auto A_C = new Edge(1, nodeA, nodeC);

    nodeA->addEdge(A_B);
    nodeA->addEdge(A_C);

    auto B_A = A_B;
    auto B_D = new Edge(1, nodeB, nodeD);
    auto B_E = new Edge(2, nodeB, nodeE);
    auto B_F = new Edge(2, nodeB, nodeF);

    nodeB->addEdge(B_A);
    nodeB->addEdge(B_D);
    nodeB->addEdge(B_E);
    nodeB->addEdge(B_F);

    auto C_F = new Edge(3, nodeC, nodeF);
    auto C_H = new Edge(1, nodeC, nodeH);

    nodeC->addEdge(C_F);
    nodeC->addEdge(C_H);

    auto D_B = B_D;

    nodeD->addEdge(D_B);

    auto E_B = B_E;
    auto E_F = new Edge(1, nodeE, nodeF);
    auto E_I = new Edge(1, nodeE, nodeI);

    nodeE->addEdge(E_B);
    nodeE->addEdge(E_F);
    nodeE->addEdge(E_I);

    auto F_B = B_F;
    auto F_C = C_F;
    auto F_E = E_F;
    auto F_G = new Edge(2, nodeF, nodeG);
    auto F_H = new Edge(2, nodeF, nodeH);
    auto F_I = new Edge(2, nodeF, nodeI);
    auto F_J = new Edge(2, nodeF, nodeJ);

    nodeF->addEdge(F_B);
    nodeF->addEdge(F_C);
    nodeF->addEdge(F_E);
    nodeF->addEdge(F_G);
    nodeF->addEdge(F_H);
    nodeF->addEdge(F_I);
    nodeF->addEdge(F_J);

    auto G_F = F_G;
    auto G_H = new Edge(1, nodeG, nodeH);
    auto G_J = new Edge(1, nodeG, nodeJ);

    nodeG->addEdge(G_F);
    nodeG->addEdge(G_H);
    nodeG->addEdge(G_J);

    auto H_C = C_H;
    auto H_F = F_H;
    auto H_G = G_H;

    nodeH->addEdge(H_C);
    nodeH->addEdge(H_F);
    nodeH->addEdge(H_G);

    auto I_E = E_I;
    auto I_F = F_I;
    auto I_J = new Edge(2, nodeI, nodeJ);

    nodeI->addEdge(I_E);
    nodeI->addEdge(I_F);
    nodeI->addEdge(I_J);

    auto J_F = F_J;
    auto J_G = G_J;
    auto J_I = I_J;

    nodeJ->addEdge(J_F);
    nodeJ->addEdge(J_G);
    nodeJ->addEdge(J_I);

    source = nodeA;
    destination = nodeJ;
}