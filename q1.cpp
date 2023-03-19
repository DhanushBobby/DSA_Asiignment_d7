#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

Node* newNode(int key) {
    Node* node = new Node;
    node->key = key;
    node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return newNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    }

    else {
        root->right = insert(root->right, key);
    }

    return root;
}

bool search(Node* root, int key) {
   if (root == nullptr || root->key == key)
      return root;

   else if (root->key > key)
      return search(root->left,key);

   else 
      return search(root->right,key);
}
 
Node* minimumKey(Node* curr)
{
	while(curr && curr->left != nullptr) {
		curr = curr->left;
	}
	return curr;
}

Node* deleteNode(Node *root,int Key)
{
	if (root == nullptr)
		return root;

	if(Key < root->key){
		root -> left = deleteNode(root -> left , Key);
	}
	
	else if(Key > root -> key){
		root -> right = deleteNode(root -> right , Key);
	}
	
	else{
		
	    if(!root -> left && !root -> right){
	        delete(root);
	        return nullptr;    
	    }
	    
	    else if(!root -> left || !root -> right){
	        Node *temp ;
	        
	        temp = (!root -> left)?(root -> right):(root -> left);
	        
	        delete(root);
	        
	        return temp;    
	    }
	    
	    else{
	        
	        Node *temp ;
	        
	        temp = minimumKey(root -> right);  
	        
	        swap(temp -> key , root -> key);  
	        
	        root -> right = deleteNode(root -> right , temp -> key);  
	    }
	    
	    
	    
	    
	    
	    
		
	}
	
	return root; 
	
}


int main() {

	Node* bst_root=nullptr;

	bst_root=insert(bst_root,8);

	insert(bst_root,3);

	insert(bst_root,10);

	insert(bst_root,1);

	insert(bst_root,6);

	insert(bst_root,-1);

	cout<<search(bst_root,-1)<<endl; 

	deleteNode(bst_root,-1);

	cout<<search(bst_root,-1)<<endl; 

	return 0;

}