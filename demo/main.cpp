// Created by nitzan on 3/31/25.
// Email: Nitzanwa@gmail.com
// ID: 209086263

#include <iostream>
#include "../include/Graph.h"
#include "../include/Algorithms.h"
#include "../include/Queue.h"
#include "../include/PriorityQueue.h"
#include "../include/UnionFind.h"

using namespace graph;

int main() {
    // Create graph with 5 vertices
    Graph g(5);

    std::cout << "\n--- Initial Graph ---\n";
    // Add edges
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 4);
    g.addEdge(4, 0, 5);

    // Print original graph
    g.printGraph();

    std::cout << "\n--- BFS Tree from Node 0 ---\n";
    Graph bfsTree = Algorithms::bfs(g, 0);
    bfsTree.printGraph();

    std::cout << "\n--- DFS Tree from Node 0 ---\n";
    Graph dfsTree = Algorithms::dfs(g, 0);
    dfsTree.printGraph();

    std::cout << "\n--- Dijkstra Tree from Node 0 ---\n";
    Graph dijkstraTree = Algorithms::dijkstra(g, 0);
    dijkstraTree.printGraph();

    std::cout << "\n--- Prim MST ---\n";
    Graph primMST = Algorithms::prim(g);
    primMST.printGraph();

    std::cout << "\n--- Kruskal MST ---\n";
    Graph kruskalMST = Algorithms::kruskal(g);
    kruskalMST.printGraph();

    std::cout << "\n--- Queue Usage ---\n";
    Queue q(3);
    q.enqueue(10);
    q.enqueue(20);

    int front = q.peek();
    std::cout << "Front of queue: " << front << std::endl;

    int removed = q.dequeue();
    std::cout << "Removed from queue: " << removed << std::endl;

    std::cout << "\n--- PriorityQueue Usage ---\n";
    PriorityQueue pq(5);
    pq.insert(2, 20);
    pq.insert(1, 10);
    pq.insert(3, 30);

    int min1 = pq.extractMin();
    std::cout << "First min extracted: " << min1 << std::endl;
    int min2 = pq.extractMin();
    std::cout << "Second min extracted: " << min2 << std::endl;

    int min3 = pq.extractMin();
    std::cout << "Third min extracted: " << min3 << std::endl;

    std::cout << "\n--- UnionFind Usage ---\n";
    UnionFind uf(6);
    uf.unionSets(0, 1);
    uf.unionSets(2, 3);

    int r1 = uf.find(1);
    std::cout << "Find(1): " << r1 << std::endl;
    int r2 = uf.find(3);
    std::cout << "Find(3): " << r2 << std::endl;

    return 0;
}
