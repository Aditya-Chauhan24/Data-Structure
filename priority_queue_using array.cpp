#include <iostream>
using namespace std;

class PriorityQueue {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE][2]; 
    int size; 

public:
    PriorityQueue() {
        size = 0;
    }

 
    void enqueue(int value, int priority) {
        if (size >= MAX_SIZE) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[size][0] = value;
        arr[size][1] = priority;
        size++;
    }

   
    int dequeue() {
        if (size == 0) {
            cout << "Queue Underflow\n";
            return -1;
        }

        int maxIndex = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i][1] > arr[maxIndex][1]) {
                maxIndex = i;
            }
        }

        int highestPriorityValue = arr[maxIndex][0];


        for (int i = maxIndex; i < size - 1; i++) {
            arr[i][0] = arr[i + 1][0];
            arr[i][1] = arr[i + 1][1];
        }

        size--; // Reduce size
        return highestPriorityValue;
    }

  
    void display() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Priority Queue (Value, Priority):\n";
        for (int i = 0; i < size; i++) {
            cout << "(" << arr[i][0] << ", " << arr[i][1] << ") ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(10, 4);
    pq.enqueue(20, 3);
    pq.enqueue(30, 2);
    pq.enqueue(40, 1);

    pq.display();

    cout << "Dequeued: " << pq.dequeue() << endl;
    pq.display();

    cout << "Dequeued: " << pq.dequeue() << endl;
    pq.display();

    return 0;
}
