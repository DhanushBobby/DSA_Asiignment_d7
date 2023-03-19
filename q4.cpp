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

void spiralLevelOrder(Node* root){
    
   if(!root) return ;
   
   stack<Node*> s1,s2 ;
   
   s1.push(root);
   
   while(!s1.empty() || !s2.empty()){
       
       while(!s1.empty()){
           
           Node* temp=s1.top();
           
           s1.pop();
           
           cout<<temp -> key<<" ";
           
           if(temp -> right) s2.push(temp -> right);
           
           if(temp -> left) s2.push(temp -> left);
       }
       
       while(!s2.empty()){
           
           Node* temp=s2.top();
           
           s2.pop();
           
           cout<<temp -> key<<" ";
           
           if(temp -> left) s1.push(temp -> left);
           
           if(temp -> right) s1.push(temp -> right);
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

	spiralLevelOrder(root); 

	return 0;

}