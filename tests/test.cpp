// Nitzanwa@gmail.com
// test.cpp - Unit tests for Graph assignment (doctest framework)

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/Graph.h"
#include "../include/Algorithms.h"
#include "../include/Queue.h"
#include "../include/PriorityQueue.h"
#include "../include/UnionFind.h"

using namespace graph;

TEST_CASE("Graph creation and edge addition") {
    Graph g(4);
    CHECK(g.getNumOfVertices() == 4);
    CHECK(g.getNumOfEdges() == 0);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    CHECK(g.getNumOfEdges() == 4);

    const Edge* neighbors = g.getNeighbors(0);
    int num = g.getNumOfNeighbors(0);
    CHECK(num == 2);
    CHECK((neighbors[0].dest == 1 || neighbors[1].dest == 1));
}

TEST_CASE("Prevent duplicate edges") {
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(0, 1);
    g.addEdge(1, 0);
    CHECK(g.getNumOfEdges() == 2); // Only one undirected edge
}

TEST_CASE("Prevent self-loops") {
    Graph g(3);
    CHECK_THROWS_AS(g.addEdge(1, 1), std::invalid_argument);
}

TEST_CASE("Edge removal") {
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    CHECK(g.getNumOfEdges() == 4);
    g.removeEdge(0, 1);
    CHECK(g.getNumOfEdges() == 2);
    CHECK_THROWS(g.removeEdge(0, 1));
}

TEST_CASE("BFS Tree") {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    Graph bfs = Algorithms::bfs(g, 0);
    CHECK(bfs.getNumOfEdges() == 6);
}

TEST_CASE("DFS Tree") {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    Graph dfs = Algorithms::dfs(g, 0);
    CHECK(dfs.getNumOfEdges() == 6);
}

TEST_CASE("Dijkstra with non-negative weights") {
    Graph g(3);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    Graph d = Algorithms::dijkstra(g, 0);
    CHECK(d.getNumOfEdges() == 2);
}

TEST_CASE("Dijkstra with negative weights - exception") {
    Graph g(2);
    g.addEdge(0, 1, -1);
    CHECK_THROWS_AS(Algorithms::dijkstra(g, 0), std::invalid_argument);
}

TEST_CASE("Prim MST") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 4);

    Graph mst = Algorithms::prim(g);
    CHECK(mst.getNumOfEdges() == 6);
}

TEST_CASE("Kruskal MST") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 4);

    Graph mst = Algorithms::kruskal(g);
    CHECK(mst.getNumOfEdges() == 6);
}

TEST_CASE("Queue basic functionality") {
    Queue q(3);
    CHECK(q.isEmpty());
    q.enqueue(1);
    q.enqueue(2);
    CHECK(q.peek() == 1);
    CHECK(q.dequeue() == 1);
    CHECK(q.getSize() == 1);
}

TEST_CASE("PriorityQueue basic functionality") {
    PriorityQueue pq(5);
    pq.insert(2, 20);
    pq.insert(1, 10);
    pq.insert(3, 30);
    CHECK(pq.extractMin() == 1);
    CHECK(pq.extractMin() == 2);
    CHECK(pq.extractMin() == 3);
    CHECK(pq.isEmpty());
}

TEST_CASE("UnionFind operations") {
    UnionFind uf(5);
    uf.unionSets(0, 1);
    uf.unionSets(2, 3);
    CHECK(uf.find(0) == uf.find(1));
    CHECK(uf.find(2) == uf.find(3));
    CHECK(uf.find(0) != uf.find(2));
}
