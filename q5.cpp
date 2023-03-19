#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

// Function to create a new node with the given key
Node* newNode(int key) {
    Node* node = new Node;
    node->key = key;
    node->left = node->right = nullptr;
    return node;
}

Node* LCA(Node* root,int n1,int n2){
    
   if(!root) return nullptr ;
   
   if(root -> key == n1 || root -> key == n2) return root ;
   
   Node* leftLCA=LCA(root -> left,n1,n2);
   
   Node* rightLCA=LCA(root -> right,n1,n2);
   
   if(leftLCA && rightLCA) return root ;
   
   return (leftLCA)?(leftLCA):(rightLCA);
    
}


int main() {

	Node* root=newNode(10);

	root->left=newNode(20);

	root->right=newNode(30);

	root->left->left=newNode(40);

	root->left->right=newNode(50);

	root->right->left=newNode(60);

	root->right->right=newNode(70);

	cout<<LCA(root,40,50)->key<<endl; 

	return 0;

}