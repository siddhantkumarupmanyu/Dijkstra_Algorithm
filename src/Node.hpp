#ifndef NODE_HPP
#define NODE_HPP
#include <string>
#include <vector>

using namespace std;

class Edge;

class Node {
   private:
    string name;
    int nodeCost;

   public:
    Node(string name);
    ~Node();
    string getName();
    int getNodeCost();
    void setNodeCost(int value);
    void addEdge(Edge* edge);
    vector<Edge*>& getConnectedEdges();
    bool equals(Node* other);
};

#endif