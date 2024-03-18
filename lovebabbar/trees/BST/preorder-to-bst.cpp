#include <bits/stdc++.h>
/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/
BinaryTreeNode<int> *solve(vector<int> &preorder, int mini, int maxi, int &i)
{
    if (i >= preorder.size())
    {
        return NULL; // if i goes out of range of preorder
    }

    if (preorder[i] < mini || preorder[i] > maxi)
        return NULL; // out of range

    // We are in range
    // Create a node
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[i++]); // we are also incrementing i by 1 to reach next element after node creation
    root->left = solve(preorder, mini, root->data, i);                  // solve for left subtree
    root->right = solve(preorder, root->data, maxi, i);                 // solve for right subtree
    return root;
}

BinaryTreeNode<int> *preorderToBST(vector<int> &preorder)
{
    // Write your code here.
    int mini = INT_MIN;   // root's minimum value can be INT_MIN
    int maxi = INT_MAX;   // root's maximum value can be INT_MAX
    int currentIndex = 0; // we start from 0th index
    return solve(preorder, mini, maxi, currentIndex);
}