#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* net;

    Node(int val) {
        this->data = val;
        this->net = NULL;
    }
    
    ~Node(){
    	
    	int val=data;
    	cout<<"descructor is called for"<<val<<endl;
	}
};

void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->net = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->net = temp;
    tail = temp;
}

void insertAtPos(Node* &head,int pos, int d){
	Node* temp = head;
	int count = 1;
	while(count<pos-1){
		temp = temp->net;
		count++;
		
		}
	Node* newnode = new Node(d);
	newnode->net = temp->net;
	temp->net = newnode;
}



void deletenode(Node* &head, int pos) {
    if (head == NULL) return; // If the list is empty, do nothing

    Node* curr = head;
    Node* per = NULL;
    int count = 1;

    // Traverse to the node at position 'pos'
    while (count < pos && curr != NULL) {
        per = curr;       // Move per to curr
        curr = curr->net; // Move curr to the next node
        count++;          // Increment count
    }

    // If the node to delete is found
    if (curr != NULL) {
        if (per == NULL) {
            // We're deleting the head node
            head = curr->net; // Update head to point to the next node
        } else {
            // Bypass the current node
            per->net = curr->net; 
        }
        
        delete curr; // Free memory for the current node
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->net;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* n2 = new Node(20);
    Node* head = n2;      
    Node* tail = n2;

    insertAtHead(head,3, 9);
    display(head);
    
    insertAtHead(head, 5);
    display(head);
    
    insertAtTail(tail, 22);
    display(head);
    
    insertAtPos(head, 33);
    display(head);
    
    deletenode(head,4);
    display(head);

    while (head != NULL) {
        Node* temp = head;
        head = head->net;
        delete temp;
    }

    return 0;
}