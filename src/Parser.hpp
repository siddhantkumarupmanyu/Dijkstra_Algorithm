#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

#include "Graph.hpp"
#include "Reader.hpp"

class Parser {
   private:
    Reader* reader;

   public:
    Parser(std::string filePath);
    ~Parser();
    void parseInto(Graph* graph);
};

#endif