#include <iostream>
#include "Graph.h"
#include "Algorithms.h"

using namespace std;
using namespace graph;

int main() {
    cout << "=== Prim's Algorithm Test ===" << endl;

    // גרף עם 6 קודקודים
    Graph g(6);

    // יצירת קשתות עם משקלים שונים
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 6);

    cout << "\n📌 Original graph:\n";
    g.printGraph();

    // הרצת פרים
    Graph mst = Algorithms::prim(g);

    cout << "\n🌲 Minimum Spanning Tree (Prim's result):\n";
    mst.printGraph();

    return 0;
}
