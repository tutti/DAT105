#ifndef EDGE_H
#define EDGE_H

#include <string>

class Node;

class Edge {
public:
    Edge(Node* v, Node* w, int wt = 0, bool d = false);
    bool isDirected;
    int weight;
    Node* endpoint[2];

    /*friend std::ostream& operator<<(std::ostream& ostr, const Edge& e) {
        ostr << e.endpoint[0]->data << " <-> " << e.endpoint[1]->data;
        return ostr;
    }*/
};

Edge::Edge(Node* v, Node* w, int wt, bool d){
    endpoint[0] = v;
    endpoint[1] = w;
    weight = wt;
    isDirected = d;
}

#endif // EDGE_H
