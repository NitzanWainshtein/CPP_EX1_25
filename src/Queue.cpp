// Nitzanwa@gmail.com
// Queue.cpp - Queue implementation for graph algorithms.

#include "../include/Queue.h"
#include <stdexcept>

namespace graph {

    /**
     * Constructor
     * @param cap Max num of elements the queue can hold
     */
    Queue::Queue(int cap) {
        if (cap <= 0) {
            throw std::invalid_argument("Queue capacity must be positive.");
        }
        capacity = cap;
        data = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    /**
     * Destructor - frees the allocated memory.
     */
    Queue::~Queue() {
        delete[] data;
    }

    /**
     * Inserts an element at the rear of the queue.
     * @param value Element to insert
     */
    void Queue::enqueue(int value) {
        if (isFull()) {
            throw std::overflow_error("Queue is full.");
        }
        data[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
    }

    /**
     * Removes and returns the front element of the queue.
     * @return The element at the front of the queue
     */
    int Queue::dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }

        int value = data[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    /**
     * Checks if the queue is empty.
     * @return true if empty, false otherwise
     */
    bool Queue::isEmpty() const {
        return size == 0;
    }

    /**
     * Checks if the queue is full.
     * @return true if full, false otherwise
     */
    bool Queue::isFull() const {
        return size == capacity;
    }

    /**
     * Returns the current number of elements in the queue.
     * @return Size of the queue
     */
    int Queue::getSize() const {
        return size;
    }

    /**
     * Returns the element at the front of the queue without removing it.
     * @return The front element
     */
    int Queue::peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return data[front];
    }
} // namespace graph
