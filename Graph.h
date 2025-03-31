//
// Created by nitzan on 3/31/25.
// Nitzanwa@gmail.com
// ID 209086263
//

#ifndef GRAPH_H
#define GRAPH_H

namespace graph {
    struct Edge {
        int dest;
        int weight;
    };

    class Graph {
    private:
        int numOfVertices;
        Edge** adjList;
        int* vSizes;
        int* vMem; //saves how much memory was allocated for specific vertex adjList

    public:
        Graph(int n);
        ~Graph();
        void addEdge(int src , int dest , int weight = 1);
        void addEdgeOneDirection(int src, int dest, int weight);
        void removeEdge(int v1 , int v2);
        bool removeEdgeOneDirection(int v1 , int v2);
        void printGraph();
        //helper functions:
        int getNumOfVertices() const;
        const Edge* getNeighbors(int v) const;
        int getNumOfNeighbors(int v) const;

    };
} // graph

#endif //GRAPH_H
