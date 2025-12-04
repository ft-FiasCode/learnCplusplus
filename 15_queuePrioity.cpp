#include <iostream>
using namespace std;

class PriorityQ {
private:
    int maxSize;        // Maximum size of the priority queue
    long* queArray;     // Array to hold the queue elements
    int nItems;        // Number of items in the queue

public:
    PriorityQ(int s) {  // Constructor
        maxSize = s;
        queArray = new long[maxSize];
        nItems = 0;
    }

    ~PriorityQ() {       // Destructor to free memory
        delete[] queArray;
    }

    void insert(long item) { // Insert item
        int j;
        if (nItems == 0) { // If no items, insert at 0
            queArray[nItems++] = item;
        } else { // If items
            for (j = nItems - 1; j >= 0; j--) { // Start at end
                if (item > queArray[j]) { // If new item larger
                    queArray[j + 1] = queArray[j]; // Shift upward
                } else { // If smaller
                    break; // Done shifting
                }
            } // end for
            queArray[j + 1] = item; // Insert it
            nItems++;
        } // end else (nItems > 0)
    } // end insert()

    long remove() { // Remove minimum item
        return queArray[--nItems];
    }

    long peekMin() { // Peek at minimum item
        return queArray[nItems - 1];
    }

    bool isEmpty() { // True if queue is empty
        return (nItems == 0);
    }

    bool isFull() { // True if queue is full
        return (nItems == maxSize);
    }
}; // end class PriorityQ

int main() {
    PriorityQ thePQ(5); // Create a priority queue with capacity of 5
    thePQ.insert(30);
    thePQ.insert(50);
    thePQ.insert(10);
    thePQ.insert(40);
    thePQ.insert(20);

    while (!thePQ.isEmpty()) {
        long item = thePQ.remove();
        cout << item << " "; // Output: 10, 20, 30, 40, 50
    } // end while
    cout << endl;

    return 0;
} // end main
