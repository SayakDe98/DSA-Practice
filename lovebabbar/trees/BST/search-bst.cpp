/*
    Following is the Binary Tree node structure:

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*/

bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    // Recursive: tc:O(n) sc:O(n)
    // Write your code here.
    if (root == NULL)
    { // if we don't get any node return false
        return false;
    }
    if (root->data == x)
    { // if we found that root's data equals target return true
        return true;
    }
    if (root->data > x)
    { // search in left subtree(left part of root) if current data is less than x
        searchInBST(root->left, x);
    }
    else
    { // search in right subtree(left part of root) if current data is more than x
        searchInBST(root->right, x);
    }

    // Iterative: tc: O(n) sc: O(1)
    // while(root != NULL) { // we run loop till we don't get nodes anymore
    //     if(root->data == x) // if we found that root's data equals target return true
    //         return true;
    //     if(root->data > x) // search in left subtree(left part of root) if current data is less than x
    //         root = root->left;
    //     else // search in right subtree(left part of root) if current data is more than x
    //         root = root->right;
    // }
    // return false; // if we don't get the target in the BST then return false
}