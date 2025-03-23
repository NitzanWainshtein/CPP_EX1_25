#include "Graph.h"
#include <iostream>
#include <stdexcept>

namespace graph {

Graph::Graph(int vertices) : numOfVertices(vertices) {
    if (vertices <= 0) {
        throw std::invalid_argument("There must be more than one vertex");
    }
    adjList = new Node *[numOfVertices];
    for (int i = 0; i < numOfVertices; i++) {
        adjList[i] = nullptr;
    }
    std::cout << "✅ Graph created with " << vertices << " vertices.\n";
}

Graph::~Graph() {
    std::cout << "🗑️ Destroying Graph and freeing memory...\n";
    for (int i = 0; i < numOfVertices; i++) {
        Node *temp = adjList[i];
        while (temp) {
            Node *currentDel = temp;
            temp = temp->next;
            delete currentDel;
        }
    }
    delete[] adjList;
    std::cout << "✅ Graph memory successfully freed.\n";
}

void Graph::addEdge(int src, int dest, int weight) {
    if (src < 0 || src >= numOfVertices || dest < 0 || dest >= numOfVertices) {
        throw std::out_of_range("One of the vertices has wrong ID");
    }

    std::cout << "➕ Adding edge (" << src << "," << dest << ") with weight " << weight << std::endl;

    Node* newNode = new Node(dest, weight);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = new Node(src, weight);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;

    std::cout << "✅ Edge (" << src << "," << dest << ") successfully added.\n";
}

void Graph::removeEdge(int v1, int v2) {
    if (v1 < 0 || v1 >= numOfVertices || v2 < 0 || v2 >= numOfVertices) {
        throw std::out_of_range("One of the vertices has wrong ID");
    }

    bool found = false;

    std::cout << "🗑️ Attempting to remove edge (" << v1 << "," << v2 << ")...\n";

    Node** curr = &adjList[v1];
    while (*curr) {
        if ((*curr)->vertex == v2) {
            std::cout << "✅ Removing edge (" << v1 << "," << v2 << ") from adjacency list of " << v1 << std::endl;
            Node* delNode = *curr;
            *curr = (*curr)->next;
            delete delNode;
            found = true;
            break;
        }
        curr = &((*curr)->next);
    }

    if (!found) {
        std::cout << "⚠️ Edge (" << v1 << "," << v2 << ") not found in adjacency list of " << v1 << std::endl;
    }

    found = false;
    curr = &adjList[v2];
    while (*curr) {
        if ((*curr)->vertex == v1) {
            std::cout << "✅ Removing edge (" << v2 << "," << v1 << ") from adjacency list of " << v2 << std::endl;
            Node* delNode = *curr;
            *curr = (*curr)->next;
            delete delNode;
            found = true;
            break;
        }
        curr = &((*curr)->next);
    }

    if (!found) {
        std::cout << "⚠️ Edge (" << v2 << "," << v1 << ") not found in adjacency list of " << v2 << std::endl;
    }

    std::cout << "✅ Edge (" << v1 << "," << v2 << ") removal completed.\n";
}

void Graph::printGraph() const {
    std::cout << "\n📌 Current Graph Structure:\n";
    for (int i = 0; i < numOfVertices; i++) {
        std::cout << "Vertex " << i << ": ";
        Node* temp = adjList[i];
        while (temp) {
            std::cout << "-> (" << temp->vertex << ", weight " << temp->weight << ") ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
    std::cout << "✅ Graph printed successfully.\n";
}

} // namespace graph
