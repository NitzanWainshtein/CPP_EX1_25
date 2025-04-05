// Nitzanwa@gmail.com
// PriorityQueue.h - Interface for a min-heap based priority queue used in graph algorithms.

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

namespace graph {

    /**
     * Priority queue implemented using a binary min-heap.
     */
    class PriorityQueue {
    private:
        struct Node {
            int vertex;   ///< Vertex index
            int priority; ///< Priority (lower value means higher priority)
        };

        Node* data;   ///< Dynamic array representing the heap
        int capacity; ///< Maximum capacity of the queue
        int size;     ///< Current number of elements in the queue

        /**
         * Swaps two elements in the heap.
         * @param i Index of first element
         * @param j Index of second element
         */
        void swap(int i, int j);

        /**
         * Restores the heap property going upwards from given index.
         * @param index Index to start heapifying up
         */
        void heapifyUp(int index);

        /**
         * Restores the heap property going downwards from given index.
         * @param index Index to start heapifying down
         */
        void heapifyDown(int index);

    public:
        /**
         * Constructor
         * @param cap Maximum number of elements in the queue
         */
        PriorityQueue(int cap);

        /**
         * Destructor - releases allocated memory.
         */
        ~PriorityQueue();

        /**
         * Inserts a new element into the queue.
         * @param vertex Vertex identifier
         * @param priority Priority value
         */
        void insert(int vertex, int priority);

        /**
         * Removes and returns the element with the smallest priority.
         * @return Vertex with minimum priority
         */
        int extractMin();

        /**
         * Checks if the queue is empty.
         * @return true if empty, false otherwise
         */
        bool isEmpty() const;
    };
}

#endif // PRIORITYQUEUE_H
