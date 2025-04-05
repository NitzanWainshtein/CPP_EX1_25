// Nitzanwa@gmail.com
// Queue.h - Interface for a circular array-based queue used in graph algorithms.

#ifndef QUEUE_H
#define QUEUE_H

namespace graph {

    /**
     * A fixed-size circular queue implementation.
     */
    class Queue {
    public:
        /**
         * Constructor
         * @param capacity Maximum number of elements in the queue
         */
        Queue(int capacity);

        /**
         * Destructor - deallocates internal array
         */
        ~Queue();

        /**
         * Inserts an element at the rear of the queue
         * @param value Element to be inserted
         */
        void enqueue(int value);

        /**
         * Removes and returns the element at the front of the queue
         * @return The front element
         */
        int dequeue();

        /**
         * Returns the front element without removing it
         * @return The front element
         */
        int peek() const;

        /**
         * Checks if the queue is empty
         * @return true if the queue is empty, false otherwise
         */
        bool isEmpty() const;

        /**
         * Checks if the queue is full
         * @return true if the queue is full, false otherwise
         */
        bool isFull() const;

        /**
         * Returns the current number of elements in the queue
         * @return Number of elements
         */
        int getSize() const;

    private:
        int *data;     ///< Dynamic array to hold queue elements
        int front;     ///< Index of the front element
        int rear;      ///< Index for inserting the next element
        int size;      ///< Current number of elements
        int capacity;  ///< Maximum capacity
    };
}

#endif // QUEUE_H
