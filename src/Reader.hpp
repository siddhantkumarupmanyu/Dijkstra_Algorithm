#ifndef READER_HPP
#define READER_HPP

#include <string>
#include <fstream>


class Reader {
   private:
    std::string filePath;
    std::fstream file;

   public:
    Reader(std::string filePath);
    ~Reader();
    std::string nextLine();
    void reset();
};

#endif