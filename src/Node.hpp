#ifndef NODE_HPP
#define NODE_HPP
#include <string>
#include <vector>

class Edge;

class Node {
   private:
    std::string name;
    int nodeCost;
    std::vector<Edge*> edges;
    bool source;
    bool destination;
    bool transversed;
    Edge* edgeWithShortestPathToSource;

   public:
    Node(std::string name);
    ~Node();
    std::string getName();
    int getNodeCost();
    void setNodeCost(int value);
    bool isSource();
    void setSource(bool value);
    bool isDestination();
    void setDestination(bool value);
    bool isTransversed();
    void setTransversed(bool value);
    void addEdge(Edge* edge);
    std::vector<Edge*>& getConnectedEdges();
    void setEdgeWithShortestPathToSource(Edge* edge);
    Edge* getEdgeWithSortestPathToSource();
    void reset();
    bool equals(Node* other);
};

#endif