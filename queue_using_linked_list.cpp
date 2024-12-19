#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "empty[Underflow]" << endl;
            return -1;
        }
        Node* temp = front;
        int value = temp->data;
        front = front->next;
        delete temp;

        if (front == nullptr) 
        {
            rear = nullptr;
        }
    return value;
    }

    void display() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue after enqueue: ";
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Queue after dequeue: ";
    q.display();

    return 0;
}
