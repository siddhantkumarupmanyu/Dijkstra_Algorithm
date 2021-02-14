#include <experimental/filesystem>
#include <fstream>
#include <iostream>

#include "Graph.hpp"
#include "catch_amalgamated.hpp"

namespace fs = std::experimental::filesystem;

using namespace std;

static void createTempFileWithText(string filePath, string text);

static void deleteTempFile(string filePath);

TEST_CASE("Parser") {
    string directory = fs::temp_directory_path();
    string filePath = directory + "/tempFile.txt";
    Graph* graph = new Graph();
    // todo
    // Parser* parser = new Parser(filePath);

    // parser.parseInto(graph);

    // REQUIRE(graph->getNodes());

    // deleteTempFile(filePath);
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