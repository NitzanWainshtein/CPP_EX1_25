#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

namespace graph {
    struct Node {
        int vertex;
        int weight;
        Node *next;
        Node(int v, int w) : vertex(v), weight(w), next(nullptr) {}
    };

    class Graph {
    private:
        int numOfVertices;
        Node **adjList;

    public:
        Graph(int vertices);
        ~Graph();

        void addEdge(int src, int dest, int weight = 1);
        void removeEdge(int v1, int v2);
        void printGraph() const;
    };
}

#endif //GRAPH_H
