#include <iostream>
#include <string>
using namespace std;

class StackX {
private:
    int maxSize;
    char* stackArray;
    int top;

public:
    StackX(int s) { // Constructor
        maxSize = s;
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

class BracketChecker {
private:
    string input; // Input string

public:
    BracketChecker(const string& in) : input(in) {} // Constructor

    void check() {
        int stackSize = input.length(); // Get max stack size
        StackX theStack(stackSize); // Make stack
        for (int j = 0; j < input.length(); j++) { // Get chars in turn
            char ch = input[j]; // Get char
            switch (ch) {
                case '{': // Opening symbols
                case '[':
                case '(':
                    theStack.push(ch); // Push them
                    break;
                case '}': // Closing symbols
                case ']':
                case ')':
                    if (!theStack.isEmpty()) { // If stack not empty
                        char chx = theStack.pop(); // Pop and check
                        if ((ch == '}' && chx != '{') ||
                            (ch == ']' && chx != '[') ||
                            (ch == ')' && chx != '(')) {
                            cout << "Error: " << ch << " at " << j << endl;
                        }
                    } else { // Prematurely empty
                        cout << "Error: " << ch << " at " << j << endl;
                    }
                    break;
                default: // No action on other characters
                    break;
            } // end switch
        } // end for
        // At this point, all characters have been processed
        if (!theStack.isEmpty()) {
            cout << "Error: missing right delimiter" << endl;
        }
    } // end check()
}; // end class BracketChecker

string getString() { // Function to read a string from input
    string s;
    cout << "Enter string containing delimiters: ";
    getline(cin, s);
    return s;
}

int main() {
    string input;
    while (true) {
        input = getString(); // Read a string from input
        if (input.empty()) // Quit if empty input
            break;

        // Make a BracketChecker
        BracketChecker theChecker(input);
        theChecker.check(); // Check brackets
    } // end while
    return 0;
} // end main
