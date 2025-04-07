// Nitzanwa@gmail.com
// Graph.cpp - Graph implementation using adjacency list

#include "../include/Graph.h"
#include <stdexcept>
#include <iostream>

namespace graph {
    /**
     * Constructor - creates a Graph with n vertices.
     * @param n number of vertices.
     */
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

    /**
     * Destructor - frees dynamic memory of adjacency lists and helper arrays.
     */
    Graph::~Graph() {
        for (int i = 0; i < numOfVertices; ++i) {
            delete[] adjList[i];
        }
        delete[] adjList;
        delete[] vSizes;
        delete[] vMem;
    }

    /**
     * Adds an undirected edge between src and dest (no duplicates, no self-loops).
     * @param src source vertex
     * @param dest destination vertex
     * @param weight edge weight
     */
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

    /**
     * Adds a single directed edge.
     * Resizes adjacency array if needed.
     * @param from source vertex
     * @param to destination vertex
     * @param weight edge weight
     */
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

    /**
     * Removes an undirected edge between v1 and v2.
     * Throws out_of_range if invalid vertices, invalid_argument if edge not found.
     */
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

    /**
     * Removes a single directed edge from 'src' to 'dest'.
     * @return true if removed, false otherwise.
     */
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

    /**
     * Prints adjacency list for each vertex.
     */
    void Graph::printGraph() {
        for (int i = 0; i < numOfVertices; i++) {
            std::cout << "Vertex " << i << ": -> ";
            for (int j = 0; j < vSizes[i]; ++j) {
                std::cout << "(v" << adjList[i][j].dest
                        << ", weight=" << adjList[i][j].weight << ") ";
            }
            std::cout << std::endl;
        }
    }

    /**
     * @return number of vertices in the graph.
     */
    int Graph::getNumOfVertices() const {
        return numOfVertices;
    }

    /**
     * Returns pointer to the neighbor array of vertex v.
     * @param v vertex index
     */
    const Edge *Graph::getNeighbors(int v) const {
        if (v < 0 || v >= numOfVertices) {
            throw std::out_of_range("Vertex index out of range");
        }
        return adjList[v];
    }

    /**
     * @param v vertex index
     * @return number of neighbors of v
     */
    int Graph::getNumOfNeighbors(int v) const {
        if (v < 0 || v >= numOfVertices) {
            throw std::out_of_range("Vertex index out of range");
        }
        return vSizes[v];
    }

    /**
     * @return total number of directed edges in the graph.
     * For an undirected graph, each edge is counted twice.
     */
    int Graph::getNumOfEdges() const {
        int edgeCount = 0;
        for (int i = 0; i < numOfVertices; ++i) {
            edgeCount += vSizes[i];
        }
        return edgeCount;
    }
} // namespace graph
