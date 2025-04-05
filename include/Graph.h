// Nitzanwa@gmail.com
// Graph.h - Graph class interface for adjacency list representation.

#ifndef GRAPH_H
#define GRAPH_H

namespace graph {

    /**
     * Represents a single edge in the graph.
     */
    struct Edge {
        int dest;   ///< Destination vertex index
        int weight; ///< Weight of the edge
    };

    /**
     * Class representing an undirected graph using adjacency lists.
     */
    class Graph {
    private:
        int numOfVertices; ///< Number of vertices in the graph
        Edge** adjList;    ///< Array of adjacency lists (one per vertex)
        int* vSizes;       ///< Current size of each adjacency list
        int* vMem;         ///< Allocated capacity for each adjacency list

    public:
        /**
         * Constructor
         * @param n Number of vertices in the graph
         */
        Graph(int n);

        /**
         * Destructor - frees all dynamically allocated memory.
         */
        ~Graph();

        /**
         * Adds an undirected edge between two vertices.
         * @param src Source vertex
         * @param dest Destination vertex
         * @param weight Weight of the edge (default is 1)
         */
        void addEdge(int src , int dest , int weight = 1);

        /**
         * Adds a one-directional edge from src to dest.
         * @param src Source vertex
         * @param dest Destination vertex
         * @param weight Edge weight
         */
        void addEdgeOneDirection(int src, int dest, int weight);

        /**
         * Removes an undirected edge between two vertices.
         * @param v1 First vertex
         * @param v2 Second vertex
         */
        void removeEdge(int v1 , int v2);

        /**
         * Removes a one-directional edge from v1 to v2.
         * @param v1 Source vertex
         * @param v2 Destination vertex
         * @return true if edge was removed, false otherwise
         */
        bool removeEdgeOneDirection(int v1 , int v2);

        /**
         * Prints the graph's adjacency list.
         */
        void printGraph();

        /**
         * Returns the number of vertices in the graph.
         */
        int getNumOfVertices() const;

        /**
         * Returns a pointer to the neighbors array of vertex v.
         * @param v Vertex index
         */
        const Edge* getNeighbors(int v) const;

        /**
         * Returns how many neighbors a given vertex has.
         * @param v Vertex index
         */
        int getNumOfNeighbors(int v) const;

        /**
         * Returns the total number of directed edges in the graph.
         */
        int getNumOfEdges() const;
    };
} // namespace graph

#endif // GRAPH_H
