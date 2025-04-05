// Nitzanwa@gmail.com
// Graph.cpp - Graph implementation using adjacency list

#include "../include/Graph.h"
#include <stdexcept>
#include <iostream>

namespace graph {
    Graph::Graph(int n) {
        if (n <= 0) {
            throw std::invalid_argument("Number of vertices must be positive");
        }
        numOfVertices = n;
        adjList = new Edge *[numOfVertices];
        vSizes = new int[numOfVertices];
        vMem = new int[numOfVertices];

        for (int i = 0; i < numOfVertices; ++i) {
            vMem[i] = 2;
            vSizes[i] = 0;
            adjList[i] = new Edge[vMem[i]];
        }
    }

    Graph::~Graph() {
        for (int i = 0; i < numOfVertices; ++i) {
            delete[] adjList[i];
        }
        delete[] adjList;
        delete[] vSizes;
        delete[] vMem;
    }

    void Graph::addEdge(int src, int dest, int weight) {
        if (src < 0 || src >= numOfVertices || dest < 0 || dest >= numOfVertices) {
            throw std::out_of_range("Vertex index out of range");
        }
        if (src == dest) {
            throw std::invalid_argument("Self-loops are not allowed");
        }

        // Prevent duplicates
        for (int i = 0; i < vSizes[src]; ++i) {
            if (adjList[src][i].dest == dest) {
                return; // Edge already exists
            }
        }

        addEdgeOneDirection(src, dest, weight);
        addEdgeOneDirection(dest, src, weight);
    }

    void Graph::addEdgeOneDirection(int from, int to, int weight) {
        if (vSizes[from] == vMem[from]) {
            int newCapacity = vMem[from] * 2;
            Edge *newAdj = new Edge[newCapacity];
            for (int i = 0; i < vSizes[from]; ++i) {
                newAdj[i] = adjList[from][i];
            }
            delete[] adjList[from];
            adjList[from] = newAdj;
            vMem[from] = newCapacity;
        }

        adjList[from][vSizes[from]].dest = to;
        adjList[from][vSizes[from]].weight = weight;
        vSizes[from]++;
    }

    void Graph::removeEdge(int v1, int v2) {
        if (v1 < 0 || v1 >= numOfVertices || v2 < 0 || v2 >= numOfVertices) {
            throw std::out_of_range("Vertex index out of range");
        }

        bool removed1 = removeEdgeOneDirection(v1, v2);
        bool removed2 = removeEdgeOneDirection(v2, v1);

        if (!removed1 || !removed2) {
            throw std::invalid_argument("Edge does not exist and cannot be removed");
        }
    }

    bool Graph::removeEdgeOneDirection(int src, int dest) {
        for (int i = 0; i < vSizes[src]; ++i) {
            if (adjList[src][i].dest == dest) {
                adjList[src][i] = adjList[src][vSizes[src] - 1];
                vSizes[src]--;
                return true;
            }
        }
        return false;
    }

    void Graph::printGraph() {
        for (int i = 0; i < numOfVertices; i++) {
            std::cout << "Vertex " << i << ": -> ";
            for (int j = 0; j < vSizes[i]; ++j) {
                std::cout << "(v" << adjList[i][j].dest << ", weight=" << adjList[i][j].weight << ") ";
            }
            std::cout << std::endl;
        }
    }

    int Graph::getNumOfVertices() const {
        return numOfVertices;
    }

    const Edge *Graph::getNeighbors(int v) const {
        if (v < 0 || v >= numOfVertices) {
            throw std::out_of_range("Vertex index out of range");
        }
        return adjList[v];
    }

    int Graph::getNumOfNeighbors(int v) const {
        if (v < 0 || v >= numOfVertices) {
            throw std::out_of_range("Vertex index out of range");
        }
        return vSizes[v];
    }

    int Graph::getNumOfEdges() const {
        int edgeCount = 0;
        for (int i = 0; i < numOfVertices; ++i) {
            edgeCount += vSizes[i];
        }
        return edgeCount;
    }
}