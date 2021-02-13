#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::experimental::filesystem;

using namespace std;

void createFile(string fileName) {
    fstream tempFile;
    tempFile.open(fileName, ios::out);

    tempFile << "Hello World 1 ...\n";
    tempFile << "Hello World 2 ...\n";
    tempFile << "Hello World 3 ...\n";
    tempFile << "Hello World 4 ...\n";

    tempFile.close();
}

void readFile(string fileName) {
    fstream tempFile(fileName, ios::in);

    tempFile.seekg(0, ios::beg);

    string line;

    while (getline(tempFile, line)) {
        cout << line << endl;
    }

    tempFile.close();
}

void deleteFile(string fileName) {
    try {
        if (fs::remove(fileName))
            std::cout << "file " << fileName << " deleted.\n";
        else
            std::cout << "file " << fileName << " not found.\n";
    } catch (const fs::filesystem_error& err) {
        std::cout << "filesystem error: " << err.what() << '\n';
    }
}

int main() {
    string directory = fs::temp_directory_path();
    string fileName = directory + "/tempFile.txt";
    createFile(fileName);
    readFile(fileName);
    deleteFile(fileName);
}