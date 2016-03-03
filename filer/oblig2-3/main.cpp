#include <iostream>
#include <vector>
#include "graph.h"
#include "edge.h"
#include "node.h"

using namespace std;

int main() {

    Graph graph;

    Node* a = new Node('a');
    Node* b = new Node('b');
    Node* c = new Node('c');
    Node* d = new Node('d');
    Node* e = new Node('e');
    Node* f = new Node('f');

    graph.insertVertex(a);
    graph.insertVertex(b);
    graph.insertVertex(c);
    graph.insertVertex(d);
    graph.insertVertex(e);
    graph.insertVertex(f);

    graph.insertEdge(a, b, 1);
    graph.insertEdge(a, c, 1);
    graph.insertEdge(a, d, 3);
    graph.insertEdge(a, f, 5);
    graph.insertEdge(b, c, 2);
    graph.insertEdge(b, e, 2);
    graph.insertEdge(e, f, 1);

    std::vector<Edge*> mst = graph.primsAlgorithm();

    for (int i = 0; i < mst.size(); ++i) {
        std::cout << "Edge " << i << ": " << mst[i]->endpoint[0]->data << " <-> " << mst[i]->endpoint[1]->data << std::endl;
    }

}