//
// Created by nitzan on 4/1/25.
//

#include "PriorityQueue.h"

#include <stdexcept>

namespace graph {
    PriorityQueue::PriorityQueue(int cap) {
        this->capacity = cap;
        size = 0;
        data = new Node[capacity];
    }

    PriorityQueue::~PriorityQueue() {
        delete[] data;
    }

    bool PriorityQueue::isEmpty() const {
        return size == 0;
    }

    void PriorityQueue::swap(int i, int j) {
        Node temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    void PriorityQueue::insert(int vertex, int priority) {
        if (size == capacity) {
            throw std::overflow_error("Queue is full.");
        }
        data[size].vertex = vertex;
        data[size].priority = priority;
        heapifyUp(size);
        size++;
    }

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
}
