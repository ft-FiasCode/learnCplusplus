#include <iostream>
using namespace std;

class Queue {
    int arr[5];
    int rear;
    int front;

public:
    Queue() {
        rear = -1;
        front = -1;
    }

    void enqueue(int z) {
        if (rear >= 4) {
            cout << "Queue is full" << endl;
        } else if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
            arr[rear] = z;
            cout << arr[rear] << " ENQUEUE at " << rear << endl;
        } else {
            rear++;
            arr[rear] = z;
            cout << arr[rear] << " inserted at place " << rear << endl;
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
        } else {
            cout << arr[front] << " DEQUEUE from " << front << endl;

            // Move the front pointer
            front++;

            // Reset the queue if it's empty after dequeue
            if (front > rear) {
                front = rear = -1;
            }
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Current Queue: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(66);
    q.enqueue(77);
    q.enqueue(88);
    q.enqueue(99);
    q.enqueue(33);
    q.enqueue(22); // This will show that the queue is full

    q.display(); // Display current queue

    q.dequeue(); // Remove an element
    q.dequeue(); // Remove another element

    q.display(); // Display current queue after dequeuing

    return 0;
}
