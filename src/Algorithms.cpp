// Nitzanwa@gmail.com
// Algorithms.cpp - Contains implementations for BFS, DFS, Dijkstra, Prim, and Kruskal algorithms.


#include "../include/Algorithms.h"

#include <stdexcept>

#include "../include/PriorityQueue.h"
#include "../include/Queue.h"
#include "../include/UnionFind.h"

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

    // Helper function for DFS traversal
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

    // DFS algorithm
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
        int n = g.getNumOfVertices();
        if (start < 0 || start >= n) {
            throw std::out_of_range("Start vertex out of range");
        }

        for (int u = 0; u < n; ++u) {
            const Edge *neighbors = g.getNeighbors(u);
            int numNeighbors = g.getNumOfNeighbors(u);
            for (int i = 0; i < numNeighbors; ++i) {
                if (neighbors[i].weight < 0) {
                    throw std::invalid_argument("Dijkstra cannot be used with negative weights");
                }
            }
        }

        const int INF = 1e9;

        Graph tree(n);
        int *distance = new int[n];
        bool *visited = new bool[n];
        int *parent = new int[n];

        for (int i = 0; i < n; ++i) {
            distance[i] = INF;
            visited[i] = false;
            parent[i] = -1;
        }

        distance[start] = 0;
        PriorityQueue pq(n * n);
        pq.insert(start, 0);

        while (!pq.isEmpty()) {
            int u = pq.extractMin();

            if (visited[u]) continue;
            visited[u] = true;

            const Edge *neighbors = g.getNeighbors(u);
            int numNeighbors = g.getNumOfNeighbors(u);

            for (int i = 0; i < numNeighbors; ++i) {
                int v = neighbors[i].dest;
                int weight = neighbors[i].weight;

                if (!visited[v] && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                    pq.insert(v, distance[v]);
                }
            }
        }

        for (int v = 0; v < n; ++v) {
            int u = parent[v];
            if (u != -1) {
                int weight = distance[v] - distance[u];
                tree.addEdgeOneDirection(u, v, weight); // directed edge
            }
        }

        delete[] distance;
        delete[] visited;
        delete[] parent;

        return tree;
    }

    Graph Algorithms::prim(const Graph &g) {
        int n = g.getNumOfVertices();
        if (n == 0) {
            throw std::invalid_argument("Graph must have at least one vertex.");
        }

        Graph mst(n);

        int *key = new int[n];
        int *parent = new int[n];
        bool *inMST = new bool[n];

        for (int i = 0; i < n; ++i) {
            key[i] = 1000000000;
            parent[i] = -1;
            inMST[i] = false;
        }

        key[0] = 0;
        PriorityQueue pq(n * n);
        pq.insert(0, 0);

        while (!pq.isEmpty()) {
            int u = pq.extractMin();
            if (inMST[u]) continue;
            inMST[u] = true;

            const Edge *neighbors = g.getNeighbors(u);
            int numNeighbors = g.getNumOfNeighbors(u);

            for (int i = 0; i < numNeighbors; ++i) {
                int v = neighbors[i].dest;
                int weight = neighbors[i].weight;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.insert(v, weight);
                }
            }
        }

        for (int v = 1; v < n; ++v) {
            int u = parent[v];
            if (u != -1) {
                int weight = key[v];
                mst.addEdge(u, v, weight);
            }
        }

        delete[] key;
        delete[] parent;
        delete[] inMST;

        return mst;
    }

    Graph Algorithms::kruskal(const Graph &g) {
        int n = g.getNumOfVertices();
        Graph mst(n);

        int maxEdges = g.getNumOfEdges() / 2;
        struct EdgeData {
            int src;
            int dest;
            int weight;
        };

        EdgeData* edges = new EdgeData[maxEdges];
        int edgeCount = 0;

        for (int i = 0; i < n; i++) {
            const Edge* neighbors = g.getNeighbors(i);
            int numNeighbors = g.getNumOfNeighbors(i);

            for (int j = 0; j < numNeighbors; j++) {
                int dest = neighbors[j].dest;
                if (i < dest) {
                    edges[edgeCount].src = i;
                    edges[edgeCount].dest = dest;
                    edges[edgeCount].weight = neighbors[j].weight;
                    edgeCount++;
                }
            }
        }

        for (int i = 0; i < edgeCount - 1; i++) {
            for (int j = 0; j < edgeCount - i - 1; j++) {
                if (edges[j].weight > edges[j + 1].weight) {
                    EdgeData temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        UnionFind uf(n);

        for (int i = 0; i < edgeCount; i++) {
            int src = edges[i].src;
            int dest = edges[i].dest;

            int set1 = uf.find(src);
            int set2 = uf.find(dest);

            if (set1 != set2) {
                mst.addEdge(src, dest, edges[i].weight);
                uf.unionSets(set1, set2);
            }
        }

        delete[] edges;
        return mst;
    }
} // graph
