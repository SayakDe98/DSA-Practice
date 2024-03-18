#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int solve(BinaryTreeNode<int> *root, int &i, int k)
{ // For k largest we need n - k + 1 smallest element
    if (root == NULL)
    { // if no node exists return -1
        return -1;
    }

    // Do inorder traversal to find the answer since in inorder we get sorted BST
    int left = solve(root->left, i, k); // For Left Subtree
    if (left != -1)
        return left;

    i++;
    if (i == k) // If current node is kth smallest element
        return root->data;
    return solve(root->right, i, k); // For right subtree
}
int kthSmallest(BinaryTreeNode<int> *root, int k)
{
    // Write your code here.
    int i = 0;
    return solve(root, i, k);
}