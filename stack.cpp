#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

 
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed onto stack.\n";
    }


    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow!\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " pop from stack.\n";
        delete temp;
    }
    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};


int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();
}

   
