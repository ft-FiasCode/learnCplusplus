#include <iostream>
using namespace std;

class ArrayQueue {
private:
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int capacity;   // Maximum number of elements queue can hold
    int* array;     // Array to hold queue elements
    int size;       // Current size of the queue

public:
    // Constructor to initialize the queue
    ArrayQueue(int cap) {
        capacity = cap;
        front = 0;
        rear = -1;
        size = 0; // Initialize size to 0
        array = new int[capacity]; // Allocate memory for the queue
    }

    // Destructor to free allocated memory
    ~ArrayQueue() {
        delete[] array; // Free the memory allocated for the array
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == capacity; // Return true if full
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0; // Return true if empty
    }

    // EnQueue operation: Inserts an element at the end of the queue
    void EnQueue(int data) {
        if (isFull()) {
            cout << "Queue overflow: Cannot enqueue " << data << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment for rear index
        array[rear] = data;            // Insert data at rear
        size++;                         // Increment size
        cout << data << " enqueued" << endl;
    }

    // DeQueue operation: Removes and returns the element at the front of the queue
    int DeQueue() {
        if (isEmpty()) {
            cout << "Queue underflow: Cannot dequeue from an empty queue." << endl;
            return -1; // Indicating empty queue
        }
        int dequeuedValue = array[front]; // Get value to return
        front = (front + 1) % capacity;   // Circular increment for front index
        size--;                            // Decrement size
        return dequeuedValue;              // Return dequeued value
    }

    // Front operation: Returns the element at the front without removing it
    int Front() {
        if (isEmpty()) {
            cout << "Queue is empty: No front element." << endl;
            return -1; // Indicating empty queue
        }
        return array[front]; // Return data of front element
    }

    // QueueSize operation: Returns the number of elements stored in the queue
    int QueueSize() {
        return size; // Return current size of the queue
    }
};

// Example usage of the ArrayQueue class
int main() {
    ArrayQueue queue(5); // Create a queue with a capacity of 5

    queue.EnQueue(10);
    queue.EnQueue(20);
    queue.EnQueue(30);

    cout << "Front element is: " << queue.Front() << endl; // Outputs: 10

    cout << "Size of queue: " << queue.QueueSize() << endl; // Outputs: 3

    cout << "Dequeued element: " << queue.DeQueue() << endl; // Outputs: 10

    cout << "Size of queue after dequeue: " << queue.QueueSize() << endl; // Outputs: 2

   while (!queue.isEmpty()) {
       cout << "Dequeued element: " << queue.DeQueue() << endl;
   }

   cout << "Trying to dequeue from an empty queue:" << endl;
   queue.DeQueue(); // Attempting to dequeue from an empty queue

   return 0;
}