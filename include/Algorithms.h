// Nitzanwa@gmail.com
// Algorithms.h - Declaration of graph algorithms: BFS, DFS, Dijkstra, Prim, and Kruskal.


#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"

namespace graph {
    class Algorithms {
    public:
        static Graph bfs(const Graph &g, int root);

        static Graph dfs(const Graph &g, int root);

        static Graph dijkstra(const Graph &g, int root);

        static Graph prim(const Graph &g);

        static Graph kruskal(const Graph &g);
    };
}

#endif // ALGORITHMS_H
