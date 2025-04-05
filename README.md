# CPP_EX1_25

**Author:** Nitzan Weissman  
**Email:** Nitzanwa@gmail.com  
**ID:** 209086263

---

## 🧠 Project Overview
This project implements an undirected graph using an **adjacency list** in C++. It includes classical graph algorithms such as BFS, DFS, Dijkstra, Prim, and Kruskal. Additionally, the project includes custom implementations of supporting data structures: Queue, PriorityQueue, and Union-Find.

The implementation is done **without using the STL**, and based entirely on low-level arrays and manual memory management, as required.

---

##  Project Structure
```
CPP_EX1_25/
├── include/           # All header (.h) files
├── src/               # Implementation (.cpp) files
├── demo/              # Main demo program
├── tests/             # Unit tests using doctest
├── Makefile           # Makefile builder
├── README.md          # This file
└── submission.txt     # Student ID + GitHub link + commit hash
```

### include/
- `Graph.h` – Graph class with relevant methods.
- `Algorithms.h` – Algorithms: BFS, DFS, Dijkstra, Prim, Kruskal.
- `Queue.h` – Basic circular queue.
- `PriorityQueue.h` – Min-heap based priority queue.
- `UnionFind.h` – Disjoint-set with path compression and union by rank.
- `doctest.h` – Header-only test framework.

### src/
- `Graph.cpp`, `Algorithms.cpp`, `Queue.cpp`, `PriorityQueue.cpp`, `UnionFind.cpp` – Implementations of all modules.

### demo/
- `main.cpp` – A full working demo showcasing all classes and algorithms including edge cases.

### tests/
- `test.cpp` – Unit tests for every module and edge case using doctest.

---

##  Features Implemented
-  Graph (Adjacency list)
-  All required algorithms (BFS, DFS, Dijkstra, Prim, Kruskal)
-  Custom data structures
-  Memory-leak free (checked with `valgrind`)
-  Unit testing for all features

---

##  Build & Run Instructions
### Requirements:
- g++ with C++11 support
- `valgrind` (for memory checks)

### Commands:
Run from project root:
```bash
make all           # Compile and run main demo
make test          # Compile and run unit tests
make valgrind      # Run main under valgrind
make valgrind-test # Run tests under valgrind
make clean         # Remove all compiled files
```

### Quick Start (One-liner):
```bash
make clean && make all && make test && make valgrind
```

---

##  GitHub Repository
Project repository: [CPP_EX1_25 on GitHub](https://github.com/NitzanWainshtein/CPP_EX1_25.git)

---
