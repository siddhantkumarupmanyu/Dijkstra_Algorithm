#include "Reader.hpp"

using namespace std;

Reader::Reader(string filePath) {
    this->filePath = filePath;
    this->file.open(filePath, ios::in);
}

Reader::~Reader() {
    this->file.close();
}

string Reader::nextLine() {
    string line;
    getline(this->file, line);
    return line;
}