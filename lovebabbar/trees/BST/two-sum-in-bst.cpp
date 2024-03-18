#include <bits/stdc++.h>
// Following is the Binary Tree node structure
/**************
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

};
***************/
void inorder(BinaryTreeNode<int> *root, vector<int> &inorderValue)
{
    if (root == NULL)
        return;

    inorder(root->left, inorderValue);
    inorderValue.push_back(root->data);
    inorder(root->right, inorderValue);
}
bool twoSumInBST(BinaryTreeNode<int> *root, int target)
{ // T.C. & S.C.: O(n)
    // Write your code here
    vector<int> inorderValue;
    inorder(root, inorderValue); // store inorder in inorderValue vector
    // Two pointer approach
    int i = 0, j = inorderValue.size() - 1;
    while (i < j)
    {
        int sum = inorderValue[i] + inorderValue[j];

        if (sum == target)
        {
            return true;
        }
        else if (sum > target)
        {
            j--; // lower the end pointer so that way sum gets lesser
        }
        else
        {
            i++; // greater the start pointer so that way sum gets greater
        }
    }
    return false; // we couldn't find a sum
}