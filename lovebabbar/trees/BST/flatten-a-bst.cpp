#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorder(TreeNode<int> *root, vector<int> &inorderVal)
{
    if (root == NULL)
        return;                       // If no node exists return from function
    inorder(root->left, inorderVal);  // Do traversal in the left subtree first
    inorderVal.push_back(root->data); // Do operation of storing the node's data in the vector
    inorder(root->right, inorderVal); // Do traversal in right subtree at last
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
    // Write your code here
    vector<int> inorderVal;
    inorder(root, inorderVal); // Store the inorder traversal in vector
    int n = inorderVal.size();

    // Create a new root
    TreeNode<int> *newRoot = new TreeNode<int>(inorderVal[0]);
    TreeNode<int> *currNode = newRoot; // Store the newRoot value in currNode
    for (int i = 1; i < n; i++)
    { // Run a loop from index = 1 to last index - 1
        // Create a temporary node
        TreeNode<int> *temp = new TreeNode<int>(inorderVal[i]);
        currNode->left = NULL;  // Point the left of current node to NULL
        currNode->right = temp; // Point the right of current node to next node
        currNode = temp;        // Move the current node to next node
    }

    currNode->left = NULL;  // Point the left of last node to NULL
    currNode->right = NULL; // Point the right of last node to NULL
    return newRoot;         // Return the root node
}
