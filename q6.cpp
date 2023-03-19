#include <iostream>
#include <queue>
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

bool findPath(Node* root,vector<Node*> &path,int k){
    
   if(!root) return false ;
   
   path.push_back(root);
   
   if(root -> key == k) return true ;
   
   if(findPath(root -> left,path,k) || findPath(root -> right,path,k)) return true ;
   
   path.pop_back();
   
   return false ;
    
}

int timeToBurn(Node* root,int leaf){
    
   vector<Node*> path ;
   
   findPath(root,path,leaf);
   
   queue<Node*> q ;
   
   for(int i=0;i<path.size();i++){
       
       q.push(path[i]);
       
       if(i == 0){
           path[i] -> left=nullptr;
           path[i] -> right=nullptr;
       }
       
       else{
           
           if(path[i] -> left == path[i-1]) path[i] -> left=nullptr;
           
           else path[i] -> right=nullptr ;
           
       }
       
   }
   
   int ans=0;
   
   while(!q.empty()){
       
       int size=q.size();
       
       while(size--){
           
           Node* temp=q.front();
           
           q.pop();
           
           if(temp -> left) q.push(temp -> left);
           
           if(temp -> right) q.push(temp -> right);
       }
       
       ans++;
       
   }
   
   return ans-1 ;
    
}


int main() {

	Node* root=newNode(10);

	root->left=newNode(20);

	root->right=newNode(30);

	root->left->left=newNode(40);

	root->left->right=newNode(50);

	root->right->left=newNode(60);

	root->right->right=newNode(70);

	cout<<timeToBurn(root,40)<<endl; 

	return 0;

}