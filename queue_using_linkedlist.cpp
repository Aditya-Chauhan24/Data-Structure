#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr; // If the queue becomes empty
            }
            cout << "Dequeued: " << temp->data << endl;
            delete temp;
        }
    }

    // Front element
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == nullptr);
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl;

    return 0;
}
