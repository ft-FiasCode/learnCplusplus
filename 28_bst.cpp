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

Node* deleteFromBst(NOode* root, int val){
	if(root==NULL){
		return root;
	}
	if(root->data === val){
		//case will go here
		//CASE:there no child
		if(root->left==NULL &&root->right==NULL){
		   delete root;
		   return NULL;
		}
	}
	else if (val < root->data){
		root->left = deleteFromBst(root->left,val);
		return root;
	}
	else{
		root->right = deleteFromBst(root->right,val);
		return root;
	}
	//case#2 deleete root with left subtree
	if(root->left!=NULL &&root->right==NULL){
	  delete root;
	  return temp;
	}
	//case#3 deleete root with right subtree
	if(root->left==NULL &&root->right!=NULL){
	  delete root;
	  return temp;
	}
	
	
}

int main() {
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

    
    int valueToDelete;
    cout << "Enter a value to delete from the BST:" << endl;
    cin >> valueToDelete;
    
    root = deleteFromBst(root, valueToDelete); 

    cout << "In-order traversal after deletion: ";
    inorder(root); 
    cout << endl;

    return 0;
}

    return 0;
}