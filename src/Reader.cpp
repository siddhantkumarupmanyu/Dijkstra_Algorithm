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

    if (!getline(this->file, line)) {
        return "";
    }
    if (line.empty()) {
        return "\n";
    }

    return line;
}

void Reader::reset() {
    this->file.seekg(0, ios::beg);
}