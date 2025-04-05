// Nitzanwa@gmail.com
// UnionFind.h - Interface for disjoint-set (Union-Find) data structure

#ifndef UNIONFIND_H
#define UNIONFIND_H

namespace graph {

    /**
     * Union-Find data structure with path compression and union by rank.
     */
    class UnionFind {
    private:
        int* parent; ///< Array to track the parent of each element
        int* rank;   ///< Array to track the rank (tree depth) of each element

    public:
        /**
         * Constructor
         * @param n Number of elements
         */
        UnionFind(int n);

        /**
         * Finds the representative (root) of the set containing x.
         * Uses path compression.
         * @param x Element to find
         * @return Root of the set
         */
        int find(int x);

        /**
         * Unites the sets containing x and y using union by rank.
         * @param x First element
         * @param y Second element
         */
        void unionSets(int x, int y);

        /**
         * Destructor - releases allocated memory.
         */
        ~UnionFind();
    };
}

#endif // UNIONFIND_H
