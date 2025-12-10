#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next; // Pointer to the next node
    Node* prev; // Pointer to the previous node
};

Node* HEAD = nullptr; // Initialize HEAD to nullptr

Node* createNode() {
    Node* n = new Node(); // Allocate memory for a new node
    n->next = nullptr; // Initialize next pointer
    n->prev = nullptr; // Initialize prev pointer
    return n;
}

// Function to insert a new node at the beginning
void insertAtBeginning() {
    Node* temp = createNode();
    cout << "Enter a number to insert at the beginning: ";
    cin >> temp->info;

    if (HEAD != nullptr) {
        temp->next = HEAD; // Link new node to current head
        HEAD->prev = temp; // Update current head's previous pointer
    }
    
    HEAD = temp; // Update head to point to the new node
}

// Function to insert a new node at the end
void insertAtEnd() {
    Node* temp = createNode();
    cout << "Enter a number to insert at the end: ";
    cin >> temp->info;

    if (HEAD == nullptr) {
        HEAD = temp; // If list is empty, new node becomes HEAD
        return;
    }

    Node* t = HEAD;
    while (t->next != nullptr) {
        t = t->next; // Traverse to the last node
    }
    
    t->next = temp; // Link the new node at the end
    temp->prev = t; // Link previous node to new node
}

// Function to insert a new node at a specific position
void insertAtPosition(int position) {
    Node* temp = createNode();
    cout << "Enter a number to insert at position " << position << ": ";
    cin >> temp->info;

    if (position == 0) {
        insertAtBeginning(); // Insert at beginning if position is 0
        return;
    }

    Node* t = HEAD;
    for (int i = 0; i < position - 1 && t != nullptr; i++) {
        t = t->next; // Traverse to one node before the desired position
    }

    if (t == nullptr) {
        cout << "Position out of bounds. Inserting at the end instead." << endl;
        delete temp; // Free allocated memory for temp since we won't use it here
        insertAtEnd(); // Call insertAtEnd if position is out of bounds
        return;
    }

    temp->next = t->next; // Link new node to next node
    if (t->next != nullptr) {
        t->next->prev = temp; // Update next node's previous pointer
    }
    
    t->next = temp; // Link previous node to new node
    temp->prev = t; // Link new node's previous pointer
}

// Function to delete a node by value
void deleteNode(int value) {
    Node* temp = HEAD;

    while (temp != nullptr && temp->info != value) {
        temp = temp->next; // Move to next node
    }

    if (temp == nullptr) {
        cout << "Value " << value << " not found in the list." << endl;
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next; // Unlink from previous node
    } else {
        HEAD = temp->next; // Update head if it's the first element being deleted
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev; // Unlink from next node
    }

    delete temp; // Free memory
    cout << "Deleted: " << value << endl;
}

// Function to display the linked list forward and backward
void displayList() {
    Node* t = HEAD;
    
    cout << "List in forward direction: ";
     cout << "nullptr <==> ";
    while (t != nullptr) {
        cout << t->info << " <=> "; // Display the node's info
        t = t->next; // Move to the next node
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

        displayList(); // Display the linked list after each operation

        cout << "Do you want to perform another operation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}