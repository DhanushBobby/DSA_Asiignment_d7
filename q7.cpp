#include <iostream>
#include <stack>
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

void inorder(Node* root){
    
   stack<Node*> s ;
   
   while(!s.empty() || root){
       
       while(root){
           
           s.push(root);
           
           root=root -> left ;
       }
       
       root=s.top();
       
       s.pop();
       
       cout<<root -> key<<" ";
       
       root=root -> right ;
   }
    
}

void preorder(Node* root){
    
   stack<Node*> s ;
   
   while(!s.empty() || root){
       
       while(root){
           
           cout<<root -> key<<" ";
           
           if(root -> right) s.push(root -> right);
           
           root=root -> left ;
       }
       
       if(!s.empty()){
           
           root=s.top();
           
           s.pop();
           
       }
       
   }
    
}


int main() {

	Node* root=newNode(10);

	root->left=newNode(20);

	root->right=newNode(30);

	root->left->left=newNode(40);

	root->left->right=newNode(50);

	root->right->left=newNode(60);

	root->right->right=newNode(70);

	inorder(root); 

	cout<<endl;

	preorder(root); 

	return 0;

}