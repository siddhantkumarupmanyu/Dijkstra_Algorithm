#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Graph.hpp"
#include "Parser.hpp"
#include "Utils.hpp"
#include "catch_amalgamated.hpp"

namespace fs = std::experimental::filesystem;

using namespace std;

static void createTempFileWithText(string filePath, string text);

static void deleteTempFile(string filePath);

static string filePath;
static Graph* graph;

static void setUp() {
    string directory = fs::temp_directory_path();
    filePath = directory + "/tempFile.txt";
    graph = new Graph();
}

static void tearDown() {
    deleteTempFile(filePath);
    delete graph;
}

TEST_CASE("Simple Parse") {
    setUp();

    stringstream ss;

    ss << "A" << endl;
    ss << "\t10 B" << endl;
    ss << "B" << endl;
    ss << "\t10 A";

    createTempFileWithText(filePath, ss.str());

    Parser* parser = new Parser(filePath);

    parser->parseInto(graph);

    vector<Node*> expectedNode;
    expectedNode.push_back(new Node("A"));
    expectedNode.push_back(new Node("B"));

    vector<Edge*> expectedEdge;
    expectedEdge.push_back(new Edge(10, new Node("A"), new Node("B")));
    // TODO:
    // assertEqualNodeVector(expectedNode, graph->getNodes());
    // assertEqualEdgeVector(expectedEdge, graph->getEdges());

    tearDown();
}

static void createTempFileWithText(string filePath, string text) {
    fstream tempFile;
    tempFile.open(filePath, ios::out);

    tempFile << text << endl;

    tempFile.close();
}

static void deleteTempFile(string filePath) {
    try {
        fs::remove(filePath);
    } catch (const fs::filesystem_error& err) {
        cout << "filesystem error: " << err.what() << '\n';
    }
}