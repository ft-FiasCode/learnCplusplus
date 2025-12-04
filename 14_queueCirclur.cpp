#include <iostream>
using namespace std;

class Queue {
private:
    int maxSize;        // Maximum size of the queue
    long* queArray;     // Array to hold the queue elements
    int front;          // Front index
    int rear;           // Rear index

public:
    Queue(int s) {      // Constructor
        maxSize = s + 1; // Array is 1 cell larger than requested
        queArray = new long[maxSize];
        front = 0;
        rear = -1;
    }

    ~Queue() {          // Destructor to free memory
        delete[] queArray;
    }

    void insert(long j) { // Put item at rear of queue
        if (rear == maxSize - 1) // Handle wraparound
            rear = -1;
        queArray[++rear] = j; // Increment rear and insert
    }

    long remove() { // Take item from front of queue
        long temp = queArray[front++];
        if (front == maxSize) // Handle wraparound
            front = 0;
        return temp;
    }

    long peek() { // Peek at front of queue
        return queArray[front];
    }

    bool isEmpty() { // True if queue is empty
        return (rear + 1 == front || (front + maxSize - 1 == rear));
    }

    bool isFull() { // True if queue is full
        return (rear + 2 == front || (front + maxSize - 2 == rear));
    }

    int size() { // Number of items in queue (assumes queue not empty)
        if (rear >= front) // Contiguous sequence
            return rear - front + 1;
        else // Broken sequence
            return (maxSize - front) + (rear + 1);
    }
}; // end class Queue

int main() {
    Queue theQueue(5); // Queue holds 5 items
    theQueue.insert(10); // Insert items
    theQueue.insert(20);
    theQueue.insert(30);
    theQueue.insert(40);

    cout << "Removed: " << theQueue.remove() << endl; // Remove one item
    cout << "Removed: " << theQueue.remove() << endl; // Remove another item

    theQueue.insert(50); // Insert more items
    theQueue.insert(60); // This will wrap around
    theQueue.insert(70);
    theQueue.insert(80);

    while (!theQueue.isEmpty()) { // Remove and display all items
        cout << "Removed: " << theQueue.remove() << endl;
    }

    return 0;
} // end main
