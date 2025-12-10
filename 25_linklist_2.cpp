#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* link;

    Node(int val) {
        this->data = val;
        this->link = NULL;
    }
    
    ~Node(){
    	cout << "Destructor called for " << data << endl;
	}
};

void insertAtHead(Node* &hea, int d) {
    Node* temp = new Node(d);
    temp->link = hea;
    hea = temp;
}

void display(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->link;
    }
    cout << "NULL" << endl;
}

int main() {
	Node* h = NULL;      
	//Node* tail = NULL;

	insertAtHead(h, 9);
	display(h);

	insertAtHead(h, 20);
	display(h);
	
	insertAtHead(h, 20);
    display(h);
	

	return 0;
}