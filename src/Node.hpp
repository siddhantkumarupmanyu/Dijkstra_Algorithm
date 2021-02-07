#ifndef NODE_HPP
#define NODE_HPP
#include <string>

using namespace std;

class Node {
   private:
    int cost;
    string name;
   public:
    Node(string name);
    ~Node();
    void setCost(int value);
    int getCost();
    string getName();
};

#endif