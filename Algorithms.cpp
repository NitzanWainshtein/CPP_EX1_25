//
// Created by nitzan on 3/31/25.
//

#include "Algorithms.h"

#include <stdexcept>

#include "PriorityQueue.h"
#include "Queue.h"
#include "UnionFind.h"

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
        int n = g.getNumOfVertices();
        if (start < 0 || start >= n) {
            throw std::out_of_range("Start vertex out of range");
        }

        // ✅ בדיקת משקלים שליליים
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

        // בניית עץ מכוון לפי parent[]
        for (int v = 0; v < n; ++v) {
            int u = parent[v];
            if (u != -1) {
                int weight = distance[v] - distance[u];
                tree.addEdgeOneDirection(u, v, weight); // ✅ חד-כיווני
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

        Graph mst(n); // עץ פורש מינימלי

        int *key = new int[n]; // משקל הקשת המינימלית לכל קודקוד
        int *parent = new int[n]; // האבא של כל קודקוד בעץ
        bool *inMST = new bool[n]; // האם כבר נוסף לעץ

        for (int i = 0; i < n; ++i) {
            key[i] = 1000000000; // INF
            parent[i] = -1;
            inMST[i] = false;
        }

        key[0] = 0; // נתחיל מ-0
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
                    pq.insert(v, weight); // אין decrease-key → פשוט מוסיפים מחדש
                }
            }
        }

        // בניית העץ מתוך parent[]
        for (int v = 1; v < n; ++v) {
            int u = parent[v];
            if (u != -1) {
                int weight = key[v];
                mst.addEdge(u, v, weight); // כי הגרף לא מכוון
            }
        }

        delete[] key;
        delete[] parent;
        delete[] inMST;

        return mst;
    }


    Graph Algorithms::kruskal(const Graph &g) {
    }
} // graph
