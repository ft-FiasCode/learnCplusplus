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

// Function to insert a new value into the BST
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

// Function to search for a value in the BST
Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;
    }
    
    if (key < root->data) {
        return search(root->left, key);
    }
    
    return search(root->right, key);
}

// Function to calculate the height of the BST
int height(Node* node) {
    if (node == nullptr) {
        return -1; // Height of an empty tree
    }
    
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    
    return max(leftHeight, rightHeight) + 1;
}

// Function to find the minimum value in the BST
int findMin(Node* root) {
    if (root == nullptr) {
        throw runtime_error("Tree is empty");
    }
    
    while (root->left != nullptr) {
        root = root->left;
    }
    
    return root->data;
}

// Function to find the maximum value in the BST
int findMax(Node* root) {
    if (root == nullptr) {
        throw runtime_error("Tree is empty");
    }
    
    while (root->right != nullptr) {
        root = root->right;
    }
    
    return root->data;
}

int main() {
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

    // Searching for a value
    int searchKey;
    cout << "Enter a value to search in the BST: ";
    cin >> searchKey;
    
    Node* searchResult = search(root, searchKey);
    
    if (searchResult != nullptr) {
        cout << "Found: " << searchResult->data << endl;
    } else {
        cout << "Not found: " << searchKey << endl;
    }

    // Calculating height of the BST
    cout << "Height of the tree: " << height(root) << endl;

    // Finding minimum and maximum values
    try {
        cout << "Minimum value: " << findMin(root) << endl;
        cout << "Maximum value: " << findMax(root) << endl;
        
   } catch (const runtime_error& e) {
       cout << e.what() << endl;
   }

   return 0;
}