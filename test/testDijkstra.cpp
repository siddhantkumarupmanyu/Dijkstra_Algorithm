#include "Dijkstra.hpp"
#include "catch_amalgamated.hpp"

// TEST_CASE("Dijkstra Constrcutor"){
//     Node*
// }

Node *source;
Node *destination;

void setUpNodes() {
    source = new Node("A");
    destination = new Node("B");

    Edge* edge = new Edge(20, source, destination);
}

TEST_CASE("Dijjstra algorithm") {
    setUpNodes();

    Dijkstra *runner = new Dijkstra(source, destination);
}