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
bool isValidBST(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
    {
        return true; // if no root node exists assume it is a valid BST
    }
    if (root->data >= min && root->data <= max) // if root node is a valid BST then check its subtrees recursively
    {
        bool leftSubtreeIsValid = isValidBST(root->left, min, root->data); // if left subtree is valid BST
        bool rightSubtreeIsValid = isValidBST(root->right, root->data, max); // if right subtree is valid BST
        return leftSubtreeIsValid && rightSubtreeIsValid; // if the whole tree is valid BST return true
    }
    else
    {
        return false;
    }
}

bool validateBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    int min = INT_MIN; // assuming root nodes min value is INT_MIN
    int max = INT_MAX; // assuming root nodes max value is INT_MAX
    return isValidBST(root, min, max);
}