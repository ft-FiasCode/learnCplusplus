#include <iostream>
using namespace std;

class StackX {
private:
    int maxSize;        // size of stack array
    long* stackArray;   // stack dynamic array
    int top;            // top of stack

public:
    StackX(int s) {     // constructor
        maxSize = s;    // set array size
        stackArray = new long[maxSize];  // create array
        top = -1;       // no items yet
    }

    ~StackX() {         // destructor to free memory
        delete[] stackArray;
    }

    void push(long j) { // put item on top of stack
        stackArray[++top] = j; // increment top, insert item
    }

    long pop() {        // take item from top of stack
        return stackArray[top--]; // access item, decrement top
    }

    long peek() {       // peek at top of stack
        return stackArray[top];
    }

    bool isEmpty() {    // true if stack is empty
        return (top == -1);
    }

    bool isFull() {     // true if stack is full
        return (top == maxSize - 1);
    }
}; // end class StackX

class StackApp {
public:
    static void main() {
        StackX theStack(10);  // make new stack
        theStack.push(20);     // push items onto stack
        theStack.push(40);
        theStack.push(60);
        theStack.push(80);
        theStack.push(90);
        while (!theStack.isEmpty()) { // until it’s empty,
            long value = theStack.pop(); // delete item from stack
            cout << value << " "; // display it
        } // end while
        cout << endl;
    } // end main
};

int main() {
    StackApp::main();
    return 0;
}
