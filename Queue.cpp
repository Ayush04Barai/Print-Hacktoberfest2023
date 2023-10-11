#include <iostream>

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return -1; // Or throw an exception
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1; // Or throw an exception
        }
        return arr[front];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Front element: " << queue.getFront() << std::endl;

    std::cout << "Dequeued element: " << queue.dequeue() << std::endl;

    std::cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
