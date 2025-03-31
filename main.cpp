#include "Graph.h"
#include "Algorithms.h"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace graph;

int main() {
    try {
        cout << "=== DFS with Cycles Test ===" << endl;

        // Create a graph with 6 vertices
        Graph g(6);

        // Build a graph that includes a cycle: 0-1-2-3-0
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(3, 0); // back edge

        // Add some more connections
        g.addEdge(2, 4);
        g.addEdge(4, 5);

        cout << "\nOriginal graph:" << endl;
        g.printGraph();

        // Run DFS from vertex 0
        Graph dfsTree = Algorithms::dfs(g, 0);

        cout << "\nDFS tree (starting from vertex 0):" << endl;
        dfsTree.printGraph();
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
