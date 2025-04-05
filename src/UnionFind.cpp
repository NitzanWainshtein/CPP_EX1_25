// Nitzanwa@gmail.com
// UnionFind.cpp - Disjoint-set (Union-Find) implementation with path compression and union by rank.

#include "../include/UnionFind.h"

namespace graph {

    /**
     * Constructor - initializes parent and rank arrays.
     * @param n Number of elements
     */
    UnionFind::UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    /**
     * Finds the representative of the set containing x using path compression.
     * @param x Element to find
     * @return Representative (root) of the set
     */
    int UnionFind::find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    /**
     * Unites the sets containing x and y using union by rank.
     * @param x First element
     * @param y Second element
     */
    void UnionFind::unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    /**
     * Destructor - releases allocated memory.
     */
    UnionFind::~UnionFind() {
        delete[] parent;
        delete[] rank;
    }
} // namespace graph
