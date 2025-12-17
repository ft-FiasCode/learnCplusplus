#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    // Constructor
    Node (int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to insert a value into the BST
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to search for a value in the BST
bool search(Node* root, int key) {
    if (root == NULL) {
        return false;
    }

    if (root->data == key) {
        return true;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function for in-order traversal
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Function for pre-order traversal
void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function for post-order traversal
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int findMin(Node* root) {
    if (root == NULL) {
        cout << "The tree is empty." << endl;
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// To Find max element in the bst
int findMax(Node* root) {
    if (root == NULL) {
        cout << "The tree is empty." << endl;
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

Node* deletefrombst(Node* root, int val){
	if (root == NULL){
		return root;
	}
	
	if( root -> data == val){
		// cases will go here
		// case1: There no child
		if(root -> left == NULL && root -> right == NULL){
			delete root;
			return NULL;
		}
		// case 2: Delete node with only left subtree
		if (root -> left != NULL && root -> right == NULL){
			Node* temp = root -> left;
			delete root;
			return temp;
		}
		// case 3: Delete node with only right subtree
		if (root -> right != NULL && root -> left == NULL){
			Node* temp = root -> right;
			delete root;
			return temp;
		}
		// case 4: Delete node with two children
		int min = findMin(root -> right);
		root -> data = min; // Replace with min value from right subtree
		root -> right = deletefrombst(root -> right, min); // Delete that min value node
		return root;
	}
	else if(val < root -> data){
		root -> left = deletefrombst(root -> left, val);
		return root;
	}
	else {
		root -> right = deletefrombst(root -> right, val);
		return root;
	}
}

int main() {
    Node* node = new Node(50);
	Node* root = node;

    // Insert values into the BST
	insert(root, 40);
	insert(root, 60);
	insert(root, 65);
	insert(root, 43);
	insert(root, 64);
	insert(root, 66);
	insert(root, 35);
	insert(root, 30);
	insert(root, 32);
	insert(root, 31);

    // Perform tree traversals
	cout << "In-order Traversal: ";
	inOrder(root);
	cout << endl;

	cout << "Pre-order Traversal: ";
	preOrder(root);
	cout << endl;

	cout << "Post-order Traversal: ";
	postOrder(root);
	cout << endl;

	cout << "Minimum value in the BST: " << findMin(root) << endl; // Find minimum value
	cout << "Maximum value in the BST: " << findMax(root) << endl; // Find maximum value

	int searchKey = 43; // Example search key
	if(search(root, searchKey)) {
	    cout << searchKey << " found in the BST." << endl; // Search for a value
	} else {
	    cout << searchKey << " not found in the BST." << endl; 
	}

	int deleteKey = 50; // Example delete key
	root = deletefrombst(root, deleteKey); // Delete a node

	cout << "In-order Traversal after Deletion of " << deleteKey << ": ";
	inOrder(root); 
	cout << endl;
	
		cout << "Pre-order Traversal: ";
	preOrder(root);
	cout << endl;

	cout << "Post-order Traversal: ";
	postOrder(root);
	cout << endl;
	

	return 0; 
}