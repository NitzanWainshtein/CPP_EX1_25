//
// Created by nitzan on 3/31/25.
//

#include "Queue.h"
#include <stdexcept>

namespace graph {
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

    Queue::~Queue() {
        delete[] data;
    }

    void Queue::enqueue(int value) {
        if (isFull()) {
            throw std::overflow_error("Queue is full.");
        }
        data[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
    }

    int Queue::dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }

        int value = data[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    bool Queue::isEmpty() const {
        return size == 0;
    }

    bool Queue::isFull() const {
        return size == capacity;
    }

    int Queue::getSize() const {
        return size;
    }

    int Queue::peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return data[front];
    }
}
