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

// Function to insert a new node with the given key in the BST
Node* insert(Node* root, int key) {
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return newNode(key);
    }

    // if the given key is less than the root's key,
    // recur for the left subtree
    if (key < root->key) {
        root->left = insert(root->left, key);
    }

    // otherwise recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }

    return root;
}

void findFloorCeil(Node* root,int &floor,int &ceil,int k){
    
   while(root){
       
       if(root -> key == k){
           floor = ceil = k ;
           break ;
       }
       
       else if(k > root -> key){
           floor = max(floor , root -> key);
           root = root -> right ;
       }
       
       else{
           ceil = min(ceil ,root ->key);
           root =  root -> left ;
       }
       
   }
    
}


int main() {

	Node* bst_root=nullptr;

	bst_root=insert(bst_root,8);

	insert(bst_root,3);

	insert(bst_root,10);

	insert(bst_root,1);

	insert(bst_root,-1);

	int floor=-1e9;

	int ceil=1e9;

	findFloorCeil(bst_root,floor,ceil,-2);

	cout<<floor<<" "<<ceil<<endl; 

	return 0;

}