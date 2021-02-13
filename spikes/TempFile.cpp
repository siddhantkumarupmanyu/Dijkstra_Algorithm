#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void createFile() {
    fstream tempFile;
    tempFile.open("tempFile.txt", ios::out);

    tempFile << "Hello World 1 ...\n";
    tempFile << "Hello World 2 ...\n";
    tempFile << "Hello World 3 ...\n";
    tempFile << "Hello World 4 ...\n";

    tempFile.close();
}

void readFile() {
    fstream tempFile("tempFile.txt", ios::in);

    tempFile.seekg(0, ios::beg);

    string line;

    while (getline(tempFile, line)) {
        cout << line << endl;
    }

    tempFile.close();
}

void deleteFile(){
    
}

int main() {
    createFile();
    readFile();
    deleteFile();
}