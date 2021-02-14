#include "Parser.hpp"

using namespace std;

Parser::Parser(string filePath) {
    this->reader = new Reader(filePath);
}

Parser::~Parser() {
    delete this->reader;
}

void Parser::parseInto(Graph* graph) {
}