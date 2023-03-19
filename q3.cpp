#include <iostream>
#include <climits>
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

int maxPathSum(Node* root,int &maxSum){
    
    if(!root) return 0 ;
    
    int leftSum=maxPathSum(root -> left,maxSum);
    
    int rightSum=maxPathSum(root -> right,maxSum);
    
    maxSum=max(maxSum,leftSum+rightSum+root -> key);
    
    return max(leftSum,rightSum)+root -> key ;
}

int main() {

	Node* root=newNode(10);

	root->left=newNode(2);

	root->right=newNode(10);

	root->left->left=newNode(20);

	root->left->right=newNode(1);

	root->right->right=newNode(-25);

	root->right->right->left=newNode(3);

	root->right->right->right=newNode(4);

	int max_sum=INT_MIN;

	maxPathSum(root,max_sum);

	cout<<max_sum<<endl; 

	return 0;

}