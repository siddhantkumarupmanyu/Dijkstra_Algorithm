#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "Reader.hpp"
#include "catch_amalgamated.hpp"

namespace fs = std::experimental::filesystem;

using namespace std;

void createTempFile(string filePath);

void deleteTempFile(string filePath);

TEST_CASE("Reader") {
    string directory = fs::temp_directory_path();
    string filePath = directory + "/tempFile.txt";
    createTempFile(filePath);

    Reader* reader = new Reader(filePath);

    REQUIRE(reader->nextLine() == "Line 1...");
    REQUIRE(reader->nextLine() == "Line 2 ...");
    REQUIRE(reader->nextLine() == "   Line 3...");
    REQUIRE(reader->nextLine() == "Line 4     ...");

    deleteTempFile(filePath);
}

void createTempFile(string filePath) {
    fstream tempFile;
    tempFile.open(filePath, ios::out);

    tempFile << "Line 1..." << endl;
    tempFile << "Line 2 ..." << endl;
    tempFile << "   Line 3..." << endl;
    tempFile << "Line 4     ..." << endl;

    tempFile.close();
}

void deleteTempFile(string filePath) {
    try {
        fs::remove(filePath);
    } catch (const fs::filesystem_error& err) {
        cout << "filesystem error: " << err.what() << '\n';
    }
}