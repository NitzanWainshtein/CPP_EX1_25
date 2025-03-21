//
// Created by nitzan on 3/21/25.
// Nitzanwa@gmail.com
//

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

namespace graph {

    class Graph {
        private:
            int numOfVertices;
        public:
            Graph(int vertices);
            ~Graph();

            void addEdge(int src , int dest , int weight = 1);
            void removeEdge(int v1 , int v2);
            void print_graph(Graph g);


#endif //GRAPH_H
