//
// Created by nitzan on 3/31/25.
//

#ifndef QUEUE_H
#define QUEUE_H

namespace graph {
    class Queue {
    public:
        Queue(int capacity);
        ~Queue();

        void enqueue(int value);
        int dequeue();
        int peek() const;
        bool isEmpty() const;
        bool isFull() const;
        int getSize() const;

    private:
        int *data;
        int front;
        int rear;
        int size;
        int capacity;
    };
}

#endif // QUEUE_H
