#include "UnionFind.h"

namespace graph {

    UnionFind::UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i; // כל קודקוד מתחיל כראש הקבוצה שלו
            rank[i] = 0;
        }
    }

    int UnionFind::find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // תיקול כל הדרך לראש הקבוצה
        return parent[x];
    }

    void UnionFind::unionSets(int x, int y) {  // שינוי ב־union -> unionSets
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

    UnionFind::~UnionFind() {
        delete[] parent;
        delete[] rank;
    }
}
