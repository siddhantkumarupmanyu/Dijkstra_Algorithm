#include "Parser.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

using namespace std;

Parser::Parser(string filePath) {
    this->reader = new Reader(filePath);
}

Parser::~Parser() {
    delete this->reader;
}

void Parser::parseInto(Graph* graph) {
    string currentLine = this->reader->nextLine();
    Node* currentNode;
    while (currentLine != "") {
        trimStringEnd(currentLine);
        if (isEdge(currentLine)) {
            string currentLineWithoutTab = currentLine.substr(currentLine.find("\t") + 1);
            vector<string> splittedStrings = splitStringByWhitespace(currentLineWithoutTab);
            int edgeCost = getEdgeCostFromString(splittedStrings[0]);
            string otherNodeName = getNodeName(splittedStrings[1]);
            Node* otherNode = addNode(graph, otherNodeName);
            addEdge(graph, edgeCost, currentNode, otherNode);
        } else {
            string nodeName = getNodeName(currentLine);
            currentNode = addNode(graph, nodeName);
        }
        currentLine = this->reader->nextLine();
    }
}

Edge* Parser::addEdge(Graph* graph, int edgeCost, Node* currentNode, Node* otherNode) {
    return graph->getOrAddEdge(new Edge(edgeCost, currentNode, otherNode));
}

Node* Parser::addNode(Graph* graph, string nodeName) {
    return graph->getOrAddNode(new Node(nodeName));
}

bool Parser::isEdge(string& str) {
    return str.rfind("\t", 0) == 0;
}

string Parser::getNodeName(string str) {
    return str;
}

int Parser::getEdgeCostFromString(string str) {
    return stoi(str);
}

void Parser::trimStringEnd(string& str) {
    str.erase(
        find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(),
        str.end());
}

// https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
vector<string> Parser::splitStringByWhitespace(string str) {
    std::istringstream iss(str);
    std::vector<std::string> results(
        std::istream_iterator<std::string>{iss},
        std::istream_iterator<std::string>());
    return results;
}
