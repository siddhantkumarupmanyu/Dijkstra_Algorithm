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
    vector<Edge*> edges;
    bool source;
    bool destination;
    bool transversed;
    Edge* edgeWithShortestPathToSource;

   public:
    Node(string name);
    ~Node();
    string getName();
    int getNodeCost();
    void setNodeCost(int value);
    bool isSource();
    void setSource(bool value);
    bool isDestination();
    void setDestination(bool value);
    bool isTransversed();
    void setTransversed(bool value);
    void addEdge(Edge* edge);
    vector<Edge*>& getConnectedEdges();
    void setEdgeWithShortestPathToSource(Edge* edge);
    Edge* getEdgeWithSortestPathToSource();
    bool equals(Node* other);
};

#endif