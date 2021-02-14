#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "Reader.hpp"
#include "catch_amalgamated.hpp"

namespace fs = std::experimental::filesystem;

using namespace std;

static void createTempFile(string filePath);

static void deleteTempFile(string filePath);

string filePath;

void setUp() {
    string directory = fs::temp_directory_path();
    filePath = directory + "/tempFile.txt";
    createTempFile(filePath);
}

void tearDown() {
    deleteTempFile(filePath);
}

TEST_CASE("Reader") {
    setUp();

    Reader* reader = new Reader(filePath);

    REQUIRE(reader->nextLine() == "Line 1...");
    REQUIRE(reader->nextLine() == "Line 2 ...");
    REQUIRE(reader->nextLine() == "   Line 3...");
    REQUIRE(reader->nextLine() == "Line 4     ...");

    tearDown();
}

TEST_CASE("\\n when newline is encountered") {
    setUp();

    Reader* reader = new Reader(filePath);

    REQUIRE(reader->nextLine() == "Line 1...");
    REQUIRE(reader->nextLine() == "Line 2 ...");
    REQUIRE(reader->nextLine() == "   Line 3...");
    REQUIRE(reader->nextLine() == "Line 4     ...");
    REQUIRE(reader->nextLine() == "\n");

    tearDown();
}

TEST_CASE("empty string when reached EOF") {
    setUp();

    Reader* reader = new Reader(filePath);

    REQUIRE(reader->nextLine() == "Line 1...");
    REQUIRE(reader->nextLine() == "Line 2 ...");
    REQUIRE(reader->nextLine() == "   Line 3...");
    REQUIRE(reader->nextLine() == "Line 4     ...");
    REQUIRE(reader->nextLine() == "\n");
    REQUIRE(reader->nextLine() == "Line 6");
    REQUIRE(reader->nextLine() == "");

    tearDown();
}

static void createTempFile(string filePath) {
    fstream tempFile;
    tempFile.open(filePath, ios::out);

    tempFile << "Line 1..." << endl;
    tempFile << "Line 2 ..." << endl;
    tempFile << "   Line 3..." << endl;
    tempFile << "Line 4     ..." << endl;
    tempFile << "" << endl;
    tempFile << "Line 6" << endl;

    tempFile.close();
}

static void deleteTempFile(string filePath) {
    try {
        fs::remove(filePath);
    } catch (const fs::filesystem_error& err) {
        cout << "filesystem error: " << err.what() << '\n';
    }
}