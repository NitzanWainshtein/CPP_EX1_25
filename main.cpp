#include "Graph.h"
#include <iostream>

using namespace graph;

void printMenu() {
    std::cout << "\n===== Graph Menu =====\n";
    std::cout << "1. Add Edge\n";
    std::cout << "2. Remove Edge\n";
    std::cout << "3. Print Graph\n";
    std::cout << "4. Exit\n";
    std::cout << "======================\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int numVertices;

    std::cout << "Enter number of vertices: ";
    std::cin >> numVertices;

    if (numVertices <= 0) {
        std::cerr << "Error: Number of vertices must be greater than 0.\n";
        return 1;
    }

    Graph g(numVertices);
    int choice;

    while (true) {
        printMenu();
        std::cin >> choice;

        if (choice == 1) {
            int src, dest, weight;
            std::cout << "Enter source vertex: ";
            std::cin >> src;
            std::cout << "Enter destination vertex: ";
            std::cin >> dest;
            std::cout << "Enter edge weight: ";
            std::cin >> weight;

            try {
                g.addEdge(src, dest, weight);
                std::cout << "✅ Edge (" << src << ", " << dest << ") added successfully.\n";
            } catch (const std::exception &e) {
                std::cerr << "❌ Error: " << e.what() << "\n";
            }

        } else if (choice == 2) {
            int src, dest;
            std::cout << "Enter source vertex: ";
            std::cin >> src;
            std::cout << "Enter destination vertex: ";
            std::cin >> dest;

            try {
                g.removeEdge(src, dest);
                std::cout << "✅ Edge (" << src << ", " << dest << ") removed successfully.\n";
            } catch (const std::exception &e) {
                std::cerr << "❌ Error: " << e.what() << "\n";
            }

        } else if (choice == 3) {
            g.printGraph();
        } else if (choice == 4) {
            std::cout << "🔚 Exiting program...\n";
            break;
        } else {
            std::cout << "❌ Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
