#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

#include "Graph.hpp"
#include "Reader.hpp"

class Parser {
   private:
    Reader* reader;
    Node* addNode(Graph* graph, std::string name);
    Edge* addEdge(Graph* graph, int edgeCost, Node* currentNode, Node* otherNode);
    bool isEdge(std::string& str);
    std::string getNodeName(std::string line);
    int getEdgeCostFromString(std::string currentLine);
    std::vector<std::string> splitStringByWhitespace(std::string str);
    void trimStringEnd(std::string& line);

   public:
    Parser(std::string filePath);
    ~Parser();
    void parseInto(Graph* graph);
};

#endif