#include <iostream>
using namespace std;

class Stack {
private:
    int stack[5]; // stack array
    int n;        // max size of the stack
    int top;      // index of the top element

public:
    Stack() : n(5), top(-1) {} // Constructor to initialize stack

    void push(int z) {
        if (top == n - 1) {
            cout << "Stack is full." << endl;
        } else {
            top++;
            stack[top] = z;
            cout << "Pushed element: " << z << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Popped element: " << stack[top] << endl;
            top--;
        }
    }

    int peek() {
        if (top != -1) {
            return stack[top];
        } else {
            cout << "Stack is empty." << endl;
            return -1; // Indicate an error
        }
    }

    void display() {
        if (top >= 0) {
            cout << "Stack elements: " << endl;
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << endl;
            }
        } else {
            cout << "Stack is empty." << endl;
        }
    }
};

int main() {
    Stack myStack; // Create an instance of Stack

    myStack.push(22);
    myStack.push(33);
    myStack.push(44);
    myStack.push(55);
    myStack.push(66);

    int y = myStack.peek();
    cout << "Top element of the stack: " << y << endl;

    myStack.display();
    myStack.pop();
    myStack.pop();
    myStack.display();

    myStack.pop();
    myStack.pop();
    myStack.display();
    
    myStack.pop();
    
    myStack.display();
    
    int v = myStack.peek();
    cout << "Top element of the stack: " << v << endl;

    return 0;
}


