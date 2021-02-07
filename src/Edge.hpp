#ifndef EDGE_HPP
#define EDGE_HPP

class Node;

class Edge {
   private:
    int cost;
    Node* firstNode;
    Node* secondNode;

   public:
    Edge(int cost, Node* firstNode, Node* secondNode);
    ~Edge();
    int getCost();
    Node* getFirstNode();
    Node* getSecondNode();
    Node* getOtherNode(Node* currentNode);
    bool equals(Edge* other);
};

#endif