// Nitzanwa@gmail.com
// PriorityQueue.cpp - Min-heap based priority queue implementation.

#include "../include/PriorityQueue.h"
#include <stdexcept>

namespace graph {

    /**
     * Constructs a priority queue with a given capacity.
     * @param cap Maximum number of elements the queue can hold
     */
    PriorityQueue::PriorityQueue(int cap) {
        this->capacity = cap;
        size = 0;
        data = new Node[capacity];
    }

    /**
     * Destructor - releases the allocated memory.
     */
    PriorityQueue::~PriorityQueue() {
        delete[] data;
    }

    /**
     * Checks if the queue is empty.
     * @return true if queue is empty, false otherwise
     */
    bool PriorityQueue::isEmpty() const {
        return size == 0;
    }

    /**
     * Swaps two nodes in the heap.
     * @param i Index of the first node
     * @param j Index of the second node
     */
    void PriorityQueue::swap(int i, int j) {
        Node temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    /**
     * Inserts a new element into the priority queue.
     * @param vertex V index
     * @param priority Priority value (lower is higher priority)
     */
    void PriorityQueue::insert(int vertex, int priority) {
        if (size == capacity) {
            throw std::overflow_error("Queue is full.");
        }
        data[size].vertex = vertex;
        data[size].priority = priority;
        heapifyUp(size);
        size++;
    }

    /**
     * Removes and returns the vertex with the minimum priority.
     * @return Vertex with the lowest priority
     */
    int PriorityQueue::extractMin() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        int minV = data[0].vertex;
        data[0] = data[size - 1];
        size--;
        heapifyDown(0);
        return minV;
    }

    /**
     * Maintains heap order by moving a node up.
     * @param index Index to start heapifying from
     */
    void PriorityQueue::heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (data[index].priority < data[parent].priority) {
                swap(index, parent);
                index = parent;
            } else {
                break;
            }
        }
    }

    /**
     * Maintains heap order by moving a node down.
     * @param index Index to start heapifying from
     */
    void PriorityQueue::heapifyDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && data[left].priority < data[smallest].priority) {
                smallest = left;
            }
            if (right < size && data[right].priority < data[smallest].priority) {
                smallest = right;
            }

            if (smallest != index) {
                swap(index, smallest);
                index = smallest;
            } else {
                break;
            }
        }
    }
} // namespace graph