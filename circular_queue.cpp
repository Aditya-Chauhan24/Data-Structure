#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* queue;   // Pointer to the queue array
    int front;    // Points to the front of the queue
    int rear;     // Points to the rear of the queue
    int size;     // Maximum size of the queue
    int count;    // Current number of elements in the queue

public:
    // Constructor to initialize the queue
    CircularQueue(int size) {
        this->size = size;
        queue = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor to free memory
    ~CircularQueue() {
        delete[] queue;
    }

    // Enqueue operation to add an element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
            return;
        }
        // Circular increment of rear
        rear = (rear + 1) % size;
        queue[rear] = value;
        count++;
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation to remove an element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << queue[front] << endl;
        // Circular increment of front
        front = (front + 1) % size;
        count--;
    }

    // Peek operation to get the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return queue[front];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (count == 0);
    }

    // Check if the queue is full
    bool isFull() {
        return (count == size);
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % size;
            cout << queue[index] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cq.enqueue(60);
    cq.enqueue(70);

    cq.display();

    cout << "Front element: " << cq.peek() << endl;

    return 0;
}
