//
// Created by nitzan on 4/1/25.
//

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H


namespace graph {
    class PriorityQueue {
    private:
        struct Node {
            int vertex;
            int priority;
        };

        Node* data;
        int capacity;
        int size;

        void swap(int i, int j);
        void heapifyUp(int index);
        void heapifyDown(int index);

    public:
        PriorityQueue(int cap);
        ~PriorityQueue();

        void insert(int vertex, int priority);
        int extractMin();
        bool isEmpty() const;
    };
}

#endif //PRIORITYQUEUE_H
