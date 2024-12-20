#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front, rear, size;

public:
    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (rear == size - 1) {
            cout << "Queue is full" << endl;
        } else {
            if (front == -1) front = 0; // First element
            rear++;
            arr[rear] = value;
            cout << "Enqueued: " << value << endl;
        }
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Dequeued: " << arr[front] << endl;
            front++;
        }
    }

    // Front element
    int peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == size - 1);
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // This will show queue is full

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl;

    return 0;
}
