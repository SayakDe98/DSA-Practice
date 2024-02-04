struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
* /

    class Solution
{
private:
    int height(Node *node)
    {
        // code here
        // base case
        if (node == NULL)
            return 0;

        int leftSubtreeHeight = height(node->left);
        int rightSubtreeHeight = height(node->right);
        return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
    }
    pair<bool, int> isBalancedFast(Node *root)
    {
        if (root == NULL)
            return {true, 0};                                       // for node as NULL we have it as balanced and height 0
        pair<bool, int> leftSubtree = isBalancedFast(root->left);   // finding isBalanced and height for left subtree
        pair<bool, int> rightSubtree = isBalancedFast(root->right); // finding isBalanced and height for right subtree

        // checking if left and right are balanced
        bool leftIsBalanced = leftSubtree.first;
        bool rightIsBalanced = rightSubtree.first;
        // finding height diff between left and right subtree
        bool heightDiff = abs(leftSubtree.second - rightSubtree.second) <= 1;
        pair<bool, int> ans;
        // storing the isBalanced and height resp in ans.first and ans.second
        ans.first = leftIsBalanced && rightIsBalanced && heightDiff;
        ans.second = max(leftSubtree.second, rightSubtree.second) + 1;
        return ans;
    }

public:
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        // if(root == NULL)
        //     return true;
        // bool leftIsBalanced = isBalanced(root -> left);
        // bool rightIsBalanced = isBalanced(root -> right);
        // bool heightDiff = abs(height(root -> left) - height(root -> right)) <= 1;
        // return leftIsBalanced && rightIsBalanced and heightDiff;
        return isBalancedFast(root).first;
    }
};