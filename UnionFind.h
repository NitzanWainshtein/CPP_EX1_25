#ifndef UNIONFIND_H
#define UNIONFIND_H

namespace graph {
    class UnionFind {
    private:
        int* parent;
        int* rank;

    public:
        UnionFind(int n);
        int find(int x);
        void unionSets(int x, int y);  // שינויים ב־union -> unionSets
        ~UnionFind();
    };
}

#endif // UNIONFIND_H
