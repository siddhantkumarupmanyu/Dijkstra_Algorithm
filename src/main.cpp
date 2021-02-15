#include <fstream>
#include <iostream>
#include <string>

#include "Dijkstra.hpp"
#include "Edge.hpp"
#include "Graph.hpp"
#include "Node.hpp"
#include "Parser.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 0;
    }

    string filePath(argv[1]);

    cout << filePath << endl;

    auto parser = new Parser(filePath);
    auto graph = new Graph();

    parser->parseInto(graph);

    graph->setSourceAndDestination(new Node("A"), new Node("J"));

    // cout << "Source Node" << graph->getSourceNode()->getName() << endl;
    // cout << "Destination Node" << graph->getDestinationNode()->getName() << endl;

    auto runner = new Dijkstra(graph->getSourceNode(), graph->getDestinationNode());

    vector<Node *> shortestPath = runner->getShortestPathToDestination();
    for (auto node : shortestPath) {
        cout << node->getName() << " --- ";
    }

    return 0;
}