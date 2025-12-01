#include <iostream>
#include <string>
using namespace std;

class StackX {
private:
    int maxSize;
    char* stackArray;
    int top;

public:
    StackX(int max) { // Constructor
        maxSize = max;
        stackArray = new char[maxSize];
        top = -1;
    }

    ~StackX() { // Destructor to free memory
        delete[] stackArray;
    }

    void push(char j) { // Put item on top of stack
        stackArray[++top] = j;
    }

    char pop() { // Take item from top of stack
        return stackArray[top--];
    }

    char peek() { // Peek at top of stack
        return stackArray[top];
    }

    bool isEmpty() { // True if stack is empty
        return (top == -1);
    }
}; // end class StackX

class Reverser {
private:
    string input; // Input string

public:
    Reverser(const string& in) : input(in) {} // Constructor

    string doRev() { // Reverse the string
        int stackSize = input.length(); // Get max stack size
        StackX theStack(stackSize); // Make stack
        for (char ch : input) {
            theStack.push(ch); // Push each character onto the stack
        }

        string output; // Output string
        while (!theStack.isEmpty()) {
            char ch = theStack.pop(); // Pop a char
            output += ch; // Append to output
        }
        return output;
    } // end doRev()
}; // end class Reverser

string getString() { // Function to read a string from input
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    return s;
}

int main() {
    string input, output;
    while (true) {
        input = getString(); // Read a string from input
        if (input.empty()) // Quit if empty input
            break;

        // Make a Reverser
        Reverser theReverser(input);
        output = theReverser.doRev(); // Use it
        cout << "Reversed: " << output << endl;
    } // end while
    return 0;
} // end main
