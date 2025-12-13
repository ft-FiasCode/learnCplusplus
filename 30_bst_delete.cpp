#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertbst(Node* root, int d) {
    if (root == nullptr) {
        return new Node(d);
    }

    if (d < root->data) {
        root->left = insertbst(root->left, d);
    } else {
        root->right = insertbst(root->right, d);
    }
    return root;
}

// Pre-order traversal: Root, Left, Right
void preorder(Node* node) {
    if (node != nullptr) {
        cout << node->data << " "; 
        preorder(node->left);       
        preorder(node->right);      
    }
}

// In-order traversal: Left, Root, Right
void inorder(Node* node) {
    if (node != nullptr) {
        inorder(node->left);        
        cout << node->data << " ";  
        inorder(node->right);       
    }
}

// Post-order traversal: Left, Right, Root
void postorder(Node* node) {
    if (node != nullptr) {
        postorder(node->left);      
        postorder(node->right);     
        cout << node->data << " ";   
    }
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* deleteFromBst(Node* root, int val) { // Corrected NOode to Node
    if (root == NULL) {
        return root; // Base case: empty tree
    }
    
    if (root->data == val) { // Corrected === to ==
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL; // Return null to indicate removal
        }
        
        // Case 2: One child
        else if (root->left == NULL) { // Only right child
            Node* temp = root->right; // Define temp
            delete root;
            return temp; // Return right child
        } else if (root->right == NULL) { // Only left child
            Node* temp = root->left; // Define temp
            delete root;
            return temp; // Return left child
        }

        // Case 3: Two children
        Node* temp = minValueNode(root->right); // Get inorder successor
        root->data = temp->data; // Copy successor's value to this node
        root->right = deleteFromBst(root->right, temp->data); // Delete successor
    } 
    else if (val < root->data) {
        root->left = deleteFromBst(root->left, val);
    } else {
        root->right = deleteFromBst(root->right, val);
    }
    
    return root; // Return unchanged node pointer
}

int main() { // Removed duplicate declaration of main
    Node* root = nullptr;
    cout << "Enter the size of the BST:" << endl;
    int size;
    cin >> size;

    cout << "Enter the elements into the BST:" << endl;
    for (int i = 1; i <= size; i++) {
        int d;
        cin >> d;
        root = insertbst(root, d);
    }

    cout << "Pre-order traversal: ";
    preorder(root);
    cout << endl;

    cout << "In-order traversal: ";
    inorder(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postorder(root);
    cout << endl;

    
    int valueToDelete;
    cout << "Enter a value to delete from the BST:" << endl;
    cin >> valueToDelete;
    
    root = deleteFromBst(root, valueToDelete); 

    cout << "In-order traversal after deletion: ";
    inorder(root); 
    cout << endl;

    return 0;
}