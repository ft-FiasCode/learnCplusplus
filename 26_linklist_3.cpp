#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* link; // Pointer to the next node
};

Node* HEAD = nullptr; // Initialize HEAD to nullptr

Node* createNode() {
    Node* n = new Node(); // Allocate memory for a new node
    return n;
}

// Function to insert a new node at the beginning
void insertAtBeginning() {
    Node* temp = createNode();
    cout << "Enter a number to insert at the beginning: ";
    cin >> temp->info;
    temp->link = HEAD; // Link new node to the current head
    HEAD = temp; // Update head to point to the new node
}

// Function to insert a new node at the end
void insertAtEnd() {
    Node* temp = createNode();
    cout << "Enter a number to insert at the end: ";
    cin >> temp->info;
    temp->link = nullptr; // New node will be the last one

    if (HEAD == nullptr) {
        HEAD = temp; // If list is empty, new node becomes HEAD
    } else {
        Node* t = HEAD;
        while (t->link != nullptr) {
            t = t->link; // Traverse to the last node
        }
        t->link = temp; // Link the new node at the end
    }
}

// Function to insert a new node at a specific position
void insertAtPosition(int position) {
    Node* temp = createNode();
    cout << "Enter a number to insert at position " << position << ": ";
    cin >> temp->info;

    if (position == 0) {
        temp->link = HEAD; // Insert at the beginning
        HEAD = temp;
        return;
    }

    Node* t = HEAD;
    for (int i = 0; i < position - 1 && t != nullptr; i++) {
        t = t->link; // Traverse to one node before the desired position
    }

    if (t == nullptr) {
        cout << "Position out of bounds. Inserting at the end instead." << endl;
        delete temp; // Free allocated memory for temp since we won't use it here
        insertAtEnd(); // Call insertAtEnd if position is out of bounds
        return;
    }

    temp->link = t->link; // Link new node to next node
    t->link = temp; // Link previous node to new node
}

// Function to delete a node by value
void deleteNode(int value) {
    Node* temp = HEAD;
    Node* prev = nullptr;

    // Check if head needs to be deleted
    if (temp != nullptr && temp->info == value) {
        HEAD = temp->link; // Change head
        delete temp; // Free old head memory
        cout << "Deleted: " << value << endl;
        return;
    }

    // Search for the key to be deleted, keep track of previous node
    while (temp != nullptr && temp->info != value) {
        prev = temp; // Keep track of previous node
        temp = temp->link; // Move to next node
    }

    // If key was not present in linked list
    if (temp == nullptr) {
        cout << "Value " << value << " not found in the list." << endl;
        return;
    }

    // Unlink the node from linked list and free memory
    prev->link = temp->link;
    delete temp; // Free memory
    cout << "Deleted: " << value << endl;
}

// Function to display the linked list
void displayList() {
    Node* t = HEAD;
    while (t != nullptr) {
        cout << t->info << " -> "; // Display the node's info
        t = t->link; // Move to the next node
    }
    cout << "nullptr" << endl; // Indicate the end of the list
}

int main() {
    char choice;

    do {
        cout << "Choose insertion type:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at specific position\n";
        cout << "4. Delete a node by value\n";  // Option for deletion
        int option;
        cin >> option;

        switch (option) {
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3: {
                int pos;
                cout << "Enter position: ";
                cin >> pos;
                insertAtPosition(pos);
                break;
            }
            case 4: {  // Handle deletion option
                int value;
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(value);
                break;
            }
            default:
                cout << "Invalid option!" << endl;
                break;
        }

        cout << "The linked list is: ";
        displayList(); // Display the linked list after each operation

        cout << "Do you want to perform another operation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}