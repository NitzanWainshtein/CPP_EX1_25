//
// Created by nitzan on 3/31/25.
//

#include "Algorithms.h"

#include <stdexcept>

#include "Queue.h"

namespace graph {
    Graph Algorithms::bfs(const Graph &g, int start) {
        int n = g.getNumOfVertices();
        if (start < 0 || start >= n) {
            throw std::out_of_range("Start vertex is out of range.");
        }

        Graph bfsTree(n);

        bool *visited = new bool[n]();

        Queue q(n);

        visited[start] = true;
        q.enqueue(start);

        while (!q.isEmpty()) {
            int u = q.dequeue();

            const Edge *uNeighbors = g.getNeighbors(u);
            int numOfNeighbors = g.getNumOfNeighbors(u);

            for (int i = 0; i < numOfNeighbors; ++i) {
                int v = uNeighbors[i].dest;
                if (!visited[v]) {
                    visited[v] = true;
                    bfsTree.addEdge(u, v, uNeighbors[i].weight);
                    q.enqueue(v);
                }
            }
        }
        delete[] visited;
        return bfsTree;
    }

    //helper function for dfs:
    void dfsVisit(const Graph &g, Graph &dfsTree, bool *visited, int u) {
        visited[u] = true;

        const Edge *neighbors = g.getNeighbors(u);
        int numNeighbors = g.getNumOfNeighbors(u);

        for (int i = 0; i < numNeighbors; ++i) {
            int v = neighbors[i].dest;

            if (!visited[v]) {
                dfsTree.addEdge(u, v, neighbors[i].weight); // Tree Edge
                dfsVisit(g, dfsTree, visited, v);
            }
        }
    }

    //dfs function:
    Graph Algorithms::dfs(const Graph &g, int start) {
        int n = g.getNumOfVertices();
        if (start < 0 || start >= n) {
            throw std::out_of_range("Start vertex is out of range.");
        }
        Graph dfsTree(n);
        bool *visited = new bool[n]();
        dfsVisit(g, dfsTree, visited, start);
        delete[] visited;

        return dfsTree;
    }

    Graph Algorithms::dijkstra(const Graph &g, int start) {
        // ...
    }

    Graph Algorithms::prim(const Graph &g) {
        // ...
    }

    Graph Algorithms::kruskal(const Graph &g) {
        // ...
    }
} // graph
