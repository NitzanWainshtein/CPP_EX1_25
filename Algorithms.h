//
// Created by nitzan on 3/31/25.
//

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

#endif //ALGORITHM_H
